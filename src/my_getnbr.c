/*
** my_getnbr.c for libmy in /home/bassintag/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:26:38 2017 Antoine Stempfer
** Last update Tue Jan 10 15:29:55 2017 Antoine Stempfer
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	sign;
  int	res;
  int	i;

  sign = 1;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      sign *= -(str[i] == '-');
      i++;
    }
  res = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res * sign);
}
