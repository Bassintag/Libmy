/*
** my_printf_flags.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov 14 15:48:12 2016 Antoine Stempfer
** Last update Thu Nov 17 11:42:04 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

static struct s_flag	get_flag(char *a, char t, char *p,
				 char *(*f)(va_list, int, int))
{
  struct s_flag		flag;

  flag.alias = a;
  flag.types = t;
  flag.prefix = p;
  flag.func = f;
  return (flag);
}

struct s_flag	*get_flags()
{
  struct s_flag	*flags;
  struct s_flag tmp;

  flags = malloc(sizeof(tmp) * NUM_FLAGS);
  flags[0] = get_flag("c", TYPE_GENERIC, "", &my_printf_char);
  flags[1] = get_flag("s", TYPE_GENERIC, "", &my_printf_str);
  flags[2] = get_flag("S", TYPE_GENERIC, "", &my_printf_strspe);
  flags[3] = get_flag("b", TYPE_NUMERIC, "0b", &my_printf_ubin);
  flags[4] = get_flag("o", TYPE_NUMERIC, "0", &my_printf_oct);
  flags[5] = get_flag("x", TYPE_NUMERIC, "0x", &my_printf_hex);
  flags[6] = get_flag("X", TYPE_NUMERIC, "0X", &my_printf_hex_up);
  flags[7] = get_flag("u", TYPE_NUMERIC, "",  &my_printf_uint);
  flags[8] = get_flag("id", TYPE_NUMERIC | TYPE_SIGNED, "", &my_printf_int);
  flags[9] = get_flag("p", TYPE_NUMERIC, "", &my_printf_pointer);
  flags[10] = get_flag("fF", TYPE_NUMERIC | TYPE_SIGNED, "", &my_printf_float);
  flags[11] = get_flag("eE", TYPE_NUMERIC | TYPE_SIGNED,
		       "", &my_printf_exponent);
  return (flags);
}
