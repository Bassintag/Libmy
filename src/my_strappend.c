/*
** my_strappend.c for libmy in /home/bassintag/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov 23 22:14:03 2016 Antoine Stempfer
** Last update Mon Nov 28 12:28:20 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

char	*my_strappend(char *a, char *b)
{
  char	*res;
  int	i;
  int	j;

  res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
  i = 0;
  while (a[i] != '\0')
    {
      res[i] = a[i];
      i++;
    }
  free(a);
  j = 0;
  while (b[j] != '\0')
    {
      res[i + j] = b[j];
      j++;
    }
  res[i + j] = '\0';
  return (res);
}
