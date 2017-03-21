/*
** my_strncpy.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Mar 20 19:26:48 2017 Antoine Stempfer
** Last update Mon Mar 20 19:27:50 2017 Antoine Stempfer
*/

#include "my.h"

int	my_strncpy(char *dest, char *src, int size)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < size)
    {
      dest[i] = src[i];
      i++;
    }
  return (i);
}
