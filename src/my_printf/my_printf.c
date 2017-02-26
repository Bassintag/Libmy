/*
** my_printf.c for libmy in /home/bassintag/delivery/PSU_2021/PSU_2021_my_printf/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 12:36:07 2016 Antoine Stempfer
** Last update Tue Nov 22 14:48:33 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"
#include "printf.h"

static int	handle_modifiers(char **mod, int *modes)
{
  if (**mod == ID_HASHTAG)
    *modes |= MODIFIER_HASHTAG;
  else if (**mod == ID_ZERO)
    *modes |= MODIFIER_ZERO;
  else if (**mod == ID_MINUS)
    *modes |= MODIFIER_MINUS;
  else if (**mod == ID_SPACE)
    *modes |= MODIFIER_SPACE;
  else if (**mod == ID_PLUS)
    *modes |= MODIFIER_PLUS;
  else if (**mod == ID_LONG)
    *modes |= MODIFIER_LONG;
  else
    return (0);
  (*mod)++;
  return (1);
}

static void	handle_zero(char *str, int mods, struct s_flag flag, int rel)
{
  int		types;

  types = flag.types;
  if (mods & MODIFIER_ZERO && types & TYPE_SIGNED)
    {
      if (*str == '-')
	my_putchar(*(str++));
      else if (mods & MODIFIER_PLUS)
	my_putchar('+');
      else if (mods & MODIFIER_SPACE)
	my_putchar(' ');
    }
  if (mods & MODIFIER_HASHTAG && mods & MODIFIER_ZERO)
    my_putstr(flag.prefix);
  if ((mods & MODIFIER_MINUS) == 0)
    while (rel-- > 0)
      {
	if (mods & MODIFIER_ZERO && types & TYPE_NUMERIC)
	  my_putchar('0');
	else
	  my_putchar(' ');
      }
}

static int	print_formated(char *str, int mod, int mod_len,
			       struct s_flag flag)
{
  int		rel;
  int		types;

  types = flag.types;
  rel = mod_len - my_strlen(str) -
    (types & TYPE_SIGNED && ((mod & MODIFIER_PLUS) || (mod & MODIFIER_SPACE)))
    - (mod & MODIFIER_HASHTAG) * my_strlen(flag.prefix);
  handle_zero(str, mod, flag, rel);
  if (types & TYPE_SIGNED && (mod & MODIFIER_ZERO) == 0 && *str != '-')
    {
      if (mod & MODIFIER_PLUS)
	my_putchar('+');
      else if (mod & MODIFIER_SPACE)
	my_putchar(' ');
    }
  else if ((mod & MODIFIER_ZERO) == 0 && mod & MODIFIER_HASHTAG)
    my_putstr(flag.prefix);
  my_putstr(str + (*str == '-' && (mod & MODIFIER_ZERO)));
  if (mod & MODIFIER_MINUS)
    while (rel-- > 0)
      my_putchar(' ');
  free(str);
  return (0);
}

static int	handle_token(char **token, va_list args, struct s_flag *flags)
{
  int		i;
  char		*tmp;
  int		modes;
  int		mod_len;
  int		precision;

  modes = 0;
  i = -1;
  precision = -1;
  while (handle_modifiers(token, &modes));
  mod_len = my_readnbr(token);
  if (**token == ID_PRECISION && (*token)++)
    precision = my_readnbr((token));
  if (**token == '%')
    return (my_putchar(**token));
  while (++i < NUM_FLAGS)
    {
      tmp = flags[i].alias - 1;
      while (*(++tmp))
	if (*tmp == **token)
	  return (print_formated((*(flags[i].func))(args, precision, modes),
				 modes, mod_len, flags[i]));
    }
  return (84);
}

int		my_printf(char *expr, ...)
{
  va_list	args;
  struct s_flag	*flags;

  flags = get_flags();
  if (!expr)
    return (84);
  va_start(args, expr);
  while (*expr)
    if (*(++expr) && *(expr - 1) == '%')
      {
	if (handle_token(&expr, args, flags) == 0)
	  expr++;
	else
	  my_putchar('%');
      }
    else
      my_putchar(*(expr - 1));
  free(flags);
  return (0);
}
