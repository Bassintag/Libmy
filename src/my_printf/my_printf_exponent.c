/*
** my_printf_exponent.c for my_printf_exponent in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf/src/my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov 14 09:32:53 2016 Antoine Stempfer
** Last update Mon Nov 14 15:35:45 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

static int    	get_exponent(double *d)
{
  int		result;

  *d = ABS(*d);
  result = 0;
  if (*d > 1)
    {
      while (*d > 10)
	{
	  *d /= 10;
	  result++;
	}
    }
  else
    {
      if (*d == 0)
	return (0);
      while (*d < 1)
	{
	  *d *= 10;
	  result--;
	}
    }
  return (result);
}

static void	my_putdecimals(double d, char *dest, int index, int num)
{
  if (num == 0)
    return ;
  d = (d - ((int) d)) * 10;
  dest[index] = ((((int) d) % 10) + 48);
  my_putdecimals(d, dest, index + 1, num - 1);
}

static void	my_putnnbr(int nb, char *dest, int index, int num)
{
  if (num == 0)
    return ;
  dest[index + (num  - 1)] = (nb % 10) + '0';
  my_putnnbr(nb / 10, dest, index, num - 1);
}

char		*my_printf_exponent(va_list args, int p)
{
  double	nb;
  int		exponent;
  char		neg;
  char		*result;
  int		i;
  int		len;

  p = (p < 0) * 6 + (p >= 0) * p;
  nb = va_arg(args, double);
  neg = nb < 0;
  exponent = get_exponent(&nb);
  len = p  + neg + 3 + (p > 0) + MAX(2, my_numlen(exponent, 10));
  result = malloc(sizeof(char) * (len + 1));
  i = 0;
  if (neg)
    result[i++] = '-';
  result[i++] = ((int) nb) + '0';
  if (p > 0)
    result[i++] = '.';
  my_putdecimals(nb, result, i, p);
  result[(i += p)] = 'e';
  result[++i] = '+' * (exponent >= 0) + '-' * (exponent < 0);
  my_putnnbr(ABS(exponent), result, ++i, MAX(2, my_numlen(exponent, 10)));
  result[len] = '\0';
  return (result);
}
