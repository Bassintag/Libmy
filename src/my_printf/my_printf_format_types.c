/*
** my_prinf_format_types.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 18:16:30 2017 Antoine Stempfer
** Last update Fri Mar 24 09:49:56 2017 Antoine Stempfer
*/

#include "printf.h"
#include "my.h"

static t_printf_type	create_type(char *alias,
				    int properties,
				    char *prefix,
				    char *(*f)(va_list, int))
{
  t_printf_type		res;

  res.alias = alias;
  res.properties = properties;
  res.prefix = prefix,
  res.func = f;
  return (res);
}

t_printf_type	*get_format_types()
{
  t_printf_type	*res;

  if ((res = malloc(sizeof(t_printf_type) * NUM_TYPES)) == NULL)
    return (NULL);
  res[0] = create_type("c", PROP_GENERIC, "", &my_printf_char);
  res[1] = create_type("s", PROP_GENERIC, "", &my_printf_str);
  res[2] = create_type("b", PROP_NUMERIC, "0b", &my_printf_bin);
  res[3] = create_type("o", PROP_NUMERIC, "0", &my_printf_oct);
  res[4] = create_type("x", PROP_NUMERIC, "0x", &my_printf_hex);
  res[5] = create_type("X", PROP_NUMERIC, "0X", &my_printf_hex_up);
  res[6] = create_type("u", PROP_NUMERIC, "", &my_printf_uint);
  res[7] = create_type("id", PROP_NUMERIC | PROP_SIGNED, "", &my_printf_int);
  res[8] = create_type("p", PROP_NUMERIC, "", &my_printf_pointer);
  res[9] = create_type("fF", PROP_NUMERIC | PROP_SIGNED, "",
			&my_printf_float);
  return (res);
}
