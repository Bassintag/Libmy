/*
** my_printf_strspe.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf/src/my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 21:10:51 2016 Antoine Stempfer
** Last update Thu Nov 10 11:47:23 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void	my_putcharcode(char c, char *dest, int *index, int i)
{
  int		save;

  if (i == 0)
    return ;
  save = --(*index);
  my_putcharcode(c / 8, dest, index, i - 1);
  dest[save] = (ABS(c % 8) + 48);
}

static int	count_spe(char *str)
{
  int		res;

  res = 0;
  while (*str)
    {
      if (*str < 32 || *str >= 127)
	res++;
      str++;
    }
  return (res);
}

char	*my_printf_strspe(va_list args)
{
  char	*str;
  char	*result;
  int	i;
  int	j;

  str = va_arg(args, char *);
  i = my_strlen(str);
  j = i + 3 * count_spe(str);
  result = malloc(sizeof(char) * (j + 1));
  result[j] = '\0';
  while (--i >= 0)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putcharcode(str[i], result, &j, 4);
	  result[j] = '\\';
	}
      else
	result[--j] = str[i];
    }
  return (result);
}
