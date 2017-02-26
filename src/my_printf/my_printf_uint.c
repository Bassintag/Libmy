/*
** my_printf_uint.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 19:50:23 2016 Antoine Stempfer
** Last update Tue Jan 10 15:51:08 2017 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void	my_put_nbr(unsigned int i, char *dest, int *index)
{
  int		save;

  if (i == 0)
    return ;
  save = --(*index);
  my_put_nbr(i / 10, dest, index);
  dest[save] = (ABS(i % 10) + 48);
}

char		*my_printf_uint(va_list args)
{
  unsigned int	nb;
  int		i;
  int		len;
  char		*result;

  nb = va_arg(args, unsigned int);
  len = my_unumlen(nb, 10);
  result = malloc(sizeof(char) * (len + 2));
  i = 0;
  if (nb == 0)
    result[i++] = '0';
  i += len;
  result[i] = '\0';
  my_put_nbr(nb, result, &i);
  return (result);
}
