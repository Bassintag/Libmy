/*
** my_removechar.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb  6 16:33:47 2017 Antoine Stempfer
** Last update Mon Feb  6 16:43:46 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

char	*my_removechar(char *str, char c)
{
  int	len;
  int	i;
  char	*res;

  len = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != c)
	len++;
      i++;
    }
  if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  res[len] = '\0';
  while (--i >= 0)
    {
      if (str[i] != c)
	{
	  len--;
	  res[len] = str[i];
	}
    }
  return (res);
}
