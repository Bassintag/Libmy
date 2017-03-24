/*
** my_printf_float.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Mar 24 09:36:30 2017 Antoine Stempfer
** Last update Fri Mar 24 12:10:41 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

static void	read_ndecimals(char *buff, double d, int precision)
{
  int		i;
  float		rnd;

  i = 0;
  rnd = .5;
  while (i < precision)
    {
      rnd /= 10;
      i++;
    }
  d = ABS(d);
  d -= (int) d;
  d += rnd;
  i = 0;
  while (i < precision)
    {
      d *= 10;
      buff[i] = ((int) d) % 10 + '0';
      i++;
    }
}

char		*my_printf_float(va_list args, int precision)
{
  char		*res;
  double       	d;
  int		i;

  d = va_arg(args, double);
  if ((res = my_numstr((int) d)) == NULL)
    return (NULL);
  if ((res = my_strappend(res, ".")) == NULL)
    return (NULL);
  if (precision <= 0)
    precision = 6;
  i = my_strlen(res);
  if ((res = ((char *) my_realloc(res, i + 1, i + 1 + precision))) == NULL)
    return (NULL);
  read_ndecimals(&res[i], d, precision);
  res[i + precision] = '\0';
  return (res);
}
