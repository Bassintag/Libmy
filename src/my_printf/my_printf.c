/*
** my_printf.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 18:02:36 2017 Antoine Stempfer
** Last update Fri Mar 31 10:41:17 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

static int	get_modifier(char c)
{
  if (c == ID_HASHTAG)
    return (MODIFIER_HASHTAG);
  if (c == ID_ZERO)
    return (MODIFIER_ZERO);
  if (c == ID_MINUS)
    return (MODIFIER_MINUS);
  if (c == ID_SPACE)
    return (MODIFIER_SPACE);
  if (c == ID_PLUS)
    return (MODIFIER_PLUS);
  return (0);
}

static char	*get_formatted(va_list args,
			       char format_id,
			       t_printf_props *props,
			       t_printf_type *types)
{
  int		i;

  props->type = NULL;
  i = 0;
  while (i < NUM_TYPES)
    {
      if (my_index_of(format_id, types[i].alias) != -1)
	{
	  props->type = &types[i];
	  return (types[i].func(args, props->prec));
	}
      i++;
    }
  return (my_puterr_null("printf: could not resolve token\n"));
}

static char		*format_token(int *i, char *str, va_list args,
				      t_printf_type *types)
{
  int			modifier;
  char			*res;
  t_printf_props	props;

  props.mods = 0;
  *i += 1;
  while ((modifier = get_modifier(str[*i])) != 0 && ++(*i))
    props.mods |= modifier;
  props.len = 0;
  while (str[*i] >= '0' && str[*i] <= '9')
    props.len = props.len * 10 + str[(*i)++] - '0';
  props.prec = 0;
  if (str[*i] == ID_PRECISION)
    {
      (*i)++;
      while (str[*i] >= '0' && str[*i] <= '9')
	props.prec = props.prec * 10 + str[(*i)++] - '0';
    }
  if ((res = get_formatted(args, str[*i], &props, types)) == NULL)
    return (NULL);
  *i += 1;
  if ((res = my_printf_apply_modifiers(res, props.type,
				       props.len, props.mods)) == NULL)
    return (my_puterr_null("printf: could not apply modifiers\n"));
  return (res);
}

static char	*format_str(char *str, va_list args, t_printf_type *types)
{
  char		*res;
  char		*tmp;
  int		i;
  int		mark;

  i = -1;
  mark = 0;
  res = NULL;
  while (str[++i] != '\0')
    if (str[i] == '%' && str[i + 1] != '%' && (i == 0 || str[i - 1] != '%'))
      {
	if ((tmp = my_substring(str, mark, i)) == NULL)
	  return (my_puterr_null("printf: out of memory\n"));
	res = my_strcombine(res, tmp);
	if ((tmp = format_token(&i, str, args, types)) == NULL)
	  return (my_puterr_null("printf: error while formatting token\n"));
	res = my_strcombine(res, tmp);
	mark = i;
	i -= 1;
      }
  if ((tmp = my_substring(str, mark, i)) == NULL)
    return (my_puterr_null("printf: out of memory\n"));
  res = my_strcombine(res, tmp);
  return (res);
}

char		*my_vaprintf(char *str, va_list args)
{
  char		*res;
  t_printf_type	*f_types;

  if (str == NULL)
    return (NULL);
  if ((f_types = get_format_types()) == NULL)
    return (NULL);
  res = format_str(str, args, f_types);
  free(f_types);
  return (res);
}
