/*
** my_strappend.c for libmy in /home/bassintag/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov 23 22:14:03 2016 Antoine Stempfer
** Last update Fri Mar 24 10:23:12 2017 Antoine Stempfer
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
  if (a != NULL)
    {
      while (a[i] != '\0')
	{
	  res[i] = a[i];
	  i++;
	}
      free(a);
    }
  j = 0;
  while (b[j] != '\0')
    {
      res[i + j] = b[j];
      j++;
    }
  res[i + j] = '\0';
  return (res);
}

char	*my_strcombine(char *a, char *b)
{
  char	*res;
  int	i;
  int	j;

  res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
  if (a != NULL)
    {
      i = -1;
      while (a[++i] != '\0')
	res[i] = a[i];
      free(a);
    }
  else
    i = 0;
  if (b != NULL)
    {
      j = -1;
      while (b[++j] != '\0')
	res[i + j] = b[j];
      res[i + j] = '\0';
      free(b);
    }
  return (res);
}
