/*
** my_memcpy.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 17:17:17 2017 Antoine Stempfer
** Last update Thu Mar 23 17:19:40 2017 Antoine Stempfer
*/

#include "my.h"

void		*my_memcpy(void *dest, void *src, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
    {
      ((char *)dest)[i] = ((char *)src)[i];
      i++;
    }
  return (dest);
}
