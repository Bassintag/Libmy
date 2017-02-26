/*
** my_printf_float.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Nov 13 15:30:38 2016 Antoine Stempfer
** Last update Tue Jan 10 15:49:45 2017 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void	my_put_nbr(int i, char *dest, int *index)
{
  int		save;

  if (i == 0)
    return ;
  save = --(*index);
  my_put_nbr(i / 10, dest, index);
  dest[save] = (ABS(i % 10) + 48);
}

static void	my_putdecimals(double d, char *dest, int index, int num)
{
  if (num == 0)
    return ;
  d = (d - ((int) d)) * 10;
  dest[index] = ((((int) d) % 10) + '0');
  my_putdecimals(d, dest, index + 1, num - 1);
}

char		*my_printf_float(va_list args, int precision)
{
  double	nb;
  int		i;
  int		len;
  char		*result;

  nb = va_arg(args, double);
  if (precision < 0)
    precision = 6;
  len = my_numlen((int) nb, 10) + precision + (precision > 0);
  result = malloc(sizeof(char) * (len + 2));
  i = 0;
  if (nb < 0)
    result[i++] = '-';
  if (nb == 0)
    result[i++] = '0';
  i += len;
  result[i] = '\0';
  i -= precision;
  my_putdecimals(nb, result, i, precision);
  if (precision > 0)
    result[--i] = '.';
  my_put_nbr((int) nb, result, &i);
  return (result);
}
