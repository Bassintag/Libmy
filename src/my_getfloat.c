/*
** my_getfloat.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Feb  2 18:15:04 2017 Antoine Stempfer
** Last update Thu Feb 23 00:48:12 2017 Antoine Stempfer
*/

#include "my.h"

static int	read_until_comma(char *str, int *i)
{
  while (str[*i] == '-' || str[*i] == '+')
    *i += 1;
  while (str[*i] != '.')
    {
      if (str[*i] < '0' || str[*i] > '9')
	return (1);
      *i += 1;
    }
  return (0);
}

float	my_getfloat(char *str)
{
  int	res;
  float	tmp;
  float	div;
  int	i;
  int	j;

  i = 0;
  res = my_getnbr(str);
  if (read_until_comma(str, &i))
    return (res);
  i++;
  div = 10;
  j = 0;
  tmp = 0;
  while (str[i + j] >= '0' && str[i + j] <= '9')
    {
      tmp += (str[i + j] - '0') / div;
      j++;
      div *= 10;
    }
  return (res + tmp);
}
