/*
** my_printf_apply_modifiers.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 22:14:52 2017 Antoine Stempfer
** Last update Thu Mar 30 11:21:58 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

static int	get_result_len(char *str, t_printf_type *type,
			       int min, int mods)
{
  int		len;

  len = my_strlen(str);
  if ((mods & MODIFIER_HASHTAG))
    len += my_strlen(type->prefix);
  if ((mods & MODIFIER_SPACE_PLUS) && (type->properties & PROP_SIGNED))
    if (len == my_strlen(str) && ((mods & MODIFIER_SPACE) || str[0] != '-'))
      len += 1;
  return (MAX(min, len));
}

static void	handle_prefix(char *res, t_printf_type *type,
			      int pos, int mods)
{
  char	c;

  if ((mods & MODIFIER_SPACE_PLUS) && (type->properties & PROP_SIGNED))
    {
      c = (mods & MODIFIER_SPACE) ? ' ' : '+';
      if ((mods & MODIFIER_ZERO_MINUS) && (c == ' ' || res[1] != '-'))
	res[0] = c;
      else if (c == ' ' || res[pos] != '-')
	res[pos - 1] = c;
    }
  if (mods & MODIFIER_HASHTAG)
    {
      if ((mods & MODIFIER_ZERO_MINUS)
	  && !(type->properties & PROP_SIGNED))
	my_strcpy(res, type->prefix);
      else
	my_strcpy(&res[pos - PREFIX_LEN], type->prefix);
    }
}

static int	get_left_index(int mods, t_printf_type *type)
{
  int		i;

  i = 0;
  if ((mods & MODIFIER_HASHTAG))
    i = PREFIX_LEN;
  if ((mods & MODIFIER_SPACE_PLUS) && (type->properties & PROP_SIGNED))
    i = MAX(i, 1);
  return (i);
}

char	*my_printf_apply_modifiers(char *str, t_printf_type *type,
				   int len, int mods)
{
  char	*res;
  int	size;

  if ((res = malloc((size = get_result_len(str, type, len, mods)) + 1))
      == NULL)
    return (NULL);
  res[size] = '\0';
  if ((mods & MODIFIER_ZERO) && !(mods & MODIFIER_MINUS)
      && (type->properties & PROP_NUMERIC))
    my_memset(res, '0', size);
  else
    my_memset(res, ' ', size);
  if ((mods & MODIFIER_MINUS))
    my_strcpy(&res[get_left_index(mods, type)], str);
  else
    my_strcpy(&res[size - my_strlen(str)], str);
  handle_prefix(res, type, size - my_strlen(str), mods);
  free(str);
  return(res);
}
