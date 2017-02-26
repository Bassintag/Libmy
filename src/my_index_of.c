/*
** my_index_of.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 15:25:31 2017 Antoine Stempfer
** Last update Thu Feb  2 16:25:06 2017 Antoine Stempfer
*/

#include "my.h"

int	my_index_of(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

int	my_index_of_str(char *target, char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (str[i + j] == target[j])
	{
	  j++;
	  if (target[j] == '\0')
	    return (i);
	  if (str[i + j] == '\0')
	    return (-1);
	}
      i++;
    }
  return (-1);
}
