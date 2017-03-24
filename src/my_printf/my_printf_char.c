/*
** my_printf_char.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:36:15 2017 Antoine Stempfer
** Last update Thu Mar 23 23:38:36 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_char(va_list args, int unused __attribute__((unused)))
{
  char	*result;

  if ((result = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  result[0] = (char) va_arg(args, int);
  result[1] = '\0';
  return (result);
}
