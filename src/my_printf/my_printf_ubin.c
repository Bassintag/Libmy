/*
** my_printf_ubin.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 20:23:18 2016 Antoine Stempfer
** Last update Thu Nov 17 12:57:22 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void	my_putbin(unsigned int nb, char *dest, int *index)
{
  int		save;

  if (nb == 0)
    return ;
  save = --(*index);
  my_putbin(nb / 2, dest, index);
  dest[save] = nb % 2 + 48;
}

char		*my_printf_ubin(va_list args)
{
  unsigned int	nb;
  int		i;
  int		len;
  char		*result;

  nb = va_arg(args, unsigned int);
  len = my_ulnumlen(nb, 2);
  result = malloc(sizeof(char) * (len + 2));
  i = 0;
  if (nb == 0)
    result[i++] = '0';
  i += len;
  result[i] = '\0';
  my_putbin(nb, result, &i);
  return (result);
}
