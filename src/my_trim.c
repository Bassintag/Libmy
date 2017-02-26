/*
** my_trim.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Feb  2 18:51:05 2017 Antoine Stempfer
** Last update Thu Feb  2 19:48:46 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

char	*my_trim_start(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  if ((res = malloc(sizeof(char) * (my_strlen(str) - 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[i + j] != '\0')
    {
      res[j] = str[i + j];
      j++;
    }
  return (res);
}
