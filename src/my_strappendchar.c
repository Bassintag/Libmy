/*
** my_strappendchar.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Mar  1 17:31:32 2017 Antoine Stempfer
** Last update Tue Mar  7 14:29:45 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

char	*my_strappendchar(char *src, char c)
{
  char	*res;
  int	i;

  res = malloc((my_strlen(src) + 2) * sizeof(char));
  i = 0;
  while (src[i] != '\0')
    {
      res[i] = src[i];
      i++;
    }
  res[i] = c;
  res[i + 1] = '\0';
  free(src);
  return (res);
}
