/*
** my_printf_str.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 18:17:28 2016 Antoine Stempfer
** Last update Mon Nov 14 14:41:52 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static	char	*get_empty_return()
{
  char		*result;
  int		i;
  int		len;

  len = my_strlen(NULL_STR);
  result = malloc(sizeof(char) * (len + 1));
  i = 0;
  while (i <= len)
    {
      result[i] = NULL_STR[i];
      i++;
    }
  return (result);
}

char	*my_printf_str(va_list args, int precision)
{
  char	*result;
  char	*str;
  int	len;
  int	i;

  str = va_arg(args, char *);
  if (str == NULL)
    return (get_empty_return());
  if (precision >= 0)
    len = MIN(precision, my_strlen(str));
  else
    len = my_strlen(str);
  result = malloc(sizeof(char) * (len + 1));
  i = 0;
  result[len] = '\0';
  while (i < len)
    {
      result[i] = str[i];
      i++;
    }
  return (result);
}
