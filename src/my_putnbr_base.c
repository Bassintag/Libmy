/*
** my_putnbr_base.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:46:21 2017 Antoine Stempfer
** Last update Tue Jan 10 15:47:40 2017 Antoine Stempfer
*/

#include "my.h"

int	my_putnbr_base(int n, char *base)
{
  int	base_len;

  if (n < 0)
    {
      n *= -1;
      my_putchar('-');
    }
  else if (n == 0)
    my_putchar('0');
  base_len = my_strlen(base);
  while (n != 0)
    {
      my_putchar(base[n % base_len]);
      n /= base_len;
    }
  return (0);
}
