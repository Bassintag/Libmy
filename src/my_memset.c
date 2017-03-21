/*
** my_memset.c for libmy in /home/bassintag
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec  7 13:23:47 2016 Antoine Stempfer
** Last update Tue Mar 21 15:36:44 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		*my_memset(void *addr, char c, size_t size)
{
  char		*cast;
  size_t	i;

  cast = addr;
  i = 0;
  while (i < size)
    {
      cast[i] = c;
      i++;
    }
  return (addr);
}
