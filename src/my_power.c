/*
** my_power.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:42:08 2017 Antoine Stempfer
** Last update Tue Jan 10 14:43:04 2017 Antoine Stempfer
*/

#include "my.h"

int	my_power(int nb, int power)
{
  if (power <= 0)
    return (1);
  if (power == 1)
    return (nb);
  return (nb * my_power(nb, power - 1));
}
