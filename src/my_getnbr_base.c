/*
** my_getnbr.c for libmy in /home/bassintag/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:26:38 2017 Antoine Stempfer
** Last update Tue Jan 10 15:47:11 2017 Antoine Stempfer
*/

#include "my.h"

int	my_getnbr_base(char *str, char *base)
{
  int	sign;
  int	res;
  int	i;
  int	base_len;
  int	index;

  sign = 1;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      sign *= -(str[i] == '-');
      i++;
    }
  base_len = my_strlen(base);
  res = 0;
  while ((index = my_index_of(str[i], base)) != -1)
    {
      res = res * base_len + index;
      i++;
    }
  return (res * sign);
}
