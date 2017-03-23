/*
** my_memcmp.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 17:39:11 2017 Antoine Stempfer
** Last update Thu Mar 23 17:47:58 2017 Antoine Stempfer
*/

#include "my.h"

int		my_memcmp(void *a, void *b, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
    {
      if (((char *)a)[i] > ((char *)b)[i])
	return (1);
      if (((char *)b)[i] > ((char *)a)[i])
	return (-1);
      i++;
    }
  return (0);
}
