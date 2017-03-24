/*
** my_printf_str.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:38:56 2017 Antoine Stempfer
** Last update Fri Mar 24 11:05:31 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_str(va_list args, int prec)
{
  char	*result;
  char	*ptr;
  int	len;

  ptr = va_arg(args, void *);
  if (ptr == NULL)
    ptr = NULL_STR;
  if (prec <= 0)
    return (my_strdup(ptr));
  len = MIN(my_strlen(ptr), prec);
  if ((result = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_strncpy(result, ptr, len);
  result[prec] = '\0';
  return (result);
}
