/*
** my_putnbr.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:46:21 2017 Antoine Stempfer
** Last update Tue Jan 10 14:50:08 2017 Antoine Stempfer
*/

#include "my.h"

int	my_putnbr(int n)
{
  if (n < 0)
    {
      n *= -1;
      my_putchar('-');
    }
  else if (n == 0)
    my_putchar('0');
  while (n != 0)
    {
      my_putchar(n % 10 + '0');
      n /= 10;
    }
  return (0);
}
