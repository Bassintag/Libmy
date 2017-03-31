/*
** my_substring.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Feb  2 15:46:42 2017 Antoine Stempfer
** Last update Fri Mar 31 10:39:58 2017 Antoine Stempfer
*/

#include "my.h"
#include <stdlib.h>

char	*my_substring(char *str, int start, int end)
{
  char	*res;
  int	i;
  int	step;

  res = NULL;
  if (start == end)
    return (my_strdup(""));
  if ((res = malloc((ABS(end - start) + 1) * sizeof(char))) != NULL)
    {
      res[ABS(end - start)] = '\0';
      step = start <= end ? 1 : -1;
      i = start;
      while (i != end)
	{
	  res[i - start] = str[i];
	  i += step;
	}
    }
  return (res);
}
