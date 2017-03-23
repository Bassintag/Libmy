/*
** my_realloc.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 17:11:43 2017 Antoine Stempfer
** Last update Thu Mar 23 17:19:51 2017 Antoine Stempfer
*/

#include "my.h"

void	*my_realloc(void *ptr, size_t curr, size_t size)
{
  void	*res;

  if ((res = malloc(size)) == NULL)
    return (NULL);
  my_memcpy(res, ptr, curr);
  free(ptr);
  return (res);
}
