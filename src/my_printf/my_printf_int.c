/*
** my_printf_int.c for libmy in /home/antoine.stempfer/delivery/PSU_2016/PSU_2016_my_printf/src/my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 16:19:29 2016 Antoine Stempfer
** Last update Tue Jan 10 15:50:07 2017 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"

static void	my_put_nbr(long i, char *dest, int *index)
{
  long		save;

  if (i == 0)
    return ;
  save = --(*index);
  my_put_nbr(i / 10, dest, index);
  dest[save] = (i % 10 + 48);
}

char	*my_printf_int(va_list args, int prec __attribute__((unused)),
		       int modes)
{
  long	nb;
  int	i;
  int	len;
  char	*result;

  if (modes & MODIFIER_LONG)
    nb = va_arg(args, long);
  else
    nb = va_arg(args, int);
  len = my_numlen(ABS(nb), 10);
  result = malloc(sizeof(char) * (len + 2));
  i = 0;
  if (nb < 0)
    result[i++] = '-';
  if (nb == 0)
    result[i++] = '0';
  else
    i += len;
  result[i] = '\0';
  my_put_nbr(ABS(nb), result, &i);
  return (result);
}
