/*
** my_numstr.c for Libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 29 16:58:09 2016 Antoine Stempfer
** Last update Tue Jan 10 15:53:59 2017 Antoine Stempfer
*/

#include "my.h"
#include <stdlib.h>

char	*my_numstr(int n)
{
  char	*res;
  int	len;
  int	i;

  len = my_numlen(n, 10);
  res = malloc(len + 1);
  res[len] = '\0';
  i = 0;
  while (i < len)
    {
      res[len - 1 - i] = n % 10 + '0';
      n /= 10;
      i++;
    }
  return (res);
}
