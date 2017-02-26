/*
** my_printf_pointer.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 20:58:52 2016 Antoine Stempfer
** Last update Tue Jan 10 15:50:38 2017 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static	char	*get_empty_return()
{
  char		*result;
  int		i;
  int		len;

  len = my_strlen(NIL_STR);
  result = malloc(sizeof(char) * (len + 1));
  i = 0;
  while (i <= len)
    {
      result[i] = NIL_STR[i];
      i++;
    }
  return (result);
}

static void	my_put_nbr(unsigned long nb, char *dest, int *index)
{
  int		save;

  if (nb == 0)
    return ;
  save = --(*index);
  my_put_nbr(nb / 16, dest, index);
  dest[save] = BASE_HEX[nb % 16];
}

char		*my_printf_pointer(va_list args)
{
  unsigned long	nb;
  int		i;
  int		len;
  void		*ptr;
  char		*result;

  ptr = va_arg(args, void *);
  if (ptr == NULL)
    return (get_empty_return());
  nb = (unsigned long) ptr;
  len = my_ulnumlen(nb, 16);
  result = malloc(sizeof(char) * (len + 4));
  i = 0;
  if (nb == 0)
    result[i++] = '0';
  else
    {
      result[i++] = '0';
      result[i++] = 'x';
    }
  i += len;
  result[i] = '\0';
  my_put_nbr(nb, result, &i);
  return (result);
}
