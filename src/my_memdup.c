/*
** my_memdup.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 18:20:07 2017 Antoine Stempfer
** Last update Thu Mar 23 18:21:32 2017 Antoine Stempfer
*/

#include "my.h"

void	*my_memdup(void *src, size_t size)
{
  void	*res;

  if ((res = malloc(size)) == NULL)
    return (NULL);
  my_memcpy(res, src, size);
  return (res);
}
