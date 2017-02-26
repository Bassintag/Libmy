/*
** my_printf_hex.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 20:33:43 2016 Antoine Stempfer
** Last update Wed Nov  9 22:26:13 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void	my_putoct(unsigned int nb, char *dest, int *index)
{
  int		save;

  if (nb == 0)
    return ;
  save = --(*index);
  my_putoct(nb / 8, dest, index);
  dest[save] = nb % 8 + 48;
}

char		*my_printf_oct(va_list args)
{
  unsigned int	nb;
  int		i;
  int		len;
  char		*result;

  nb = va_arg(args, unsigned int);
  len = my_unumlen(nb, 8);
  result = malloc(sizeof(char) * (len + 2));
  i = 0;
  if (nb == 0)
    result[i++] = '0';
  i += len;
  result[i] = '\0';
  my_putoct(nb, result, &i);
  return (result);
}
