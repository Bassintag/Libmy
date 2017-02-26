/*
** my_substring.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Feb  2 15:46:42 2017 Antoine Stempfer
** Last update Thu Feb  2 15:54:46 2017 Antoine Stempfer
*/

#include "my.h"
#include <stdlib.h>

char	*my_substring(char *str, int start, int end)
{
  char	*res;
  int	i;
  int	step;

  if ((res = malloc((ABS(start - end) + 1) * sizeof(char))) != NULL)
    {
      res[ABS(start - end)] = '\0';
      step = start <= end ? 1 : -1;
      i = start;
      while (i != end)
	{
	  res[i] = str[i];
	  i += step;
	}
    }
  return (res);
}
