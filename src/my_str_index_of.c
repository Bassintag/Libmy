/*
** my_str_index_of.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Jan 11 15:59:41 2017 Antoine Stempfer
** Last update Wed Jan 11 16:02:12 2017 Antoine Stempfer
*/

#include "my.h"

int	my_str_index_of(char *match, char *str)
{
  int	i;
  int	j;
  int	max;

  i = 0;
  max = my_strlen(str) - my_strlen(match);
  while (i <= max)
    {
      j = 0;
      while (match[j] == str[i + j])
	{
	  j++;
	  if (match[j] == '\0')
	    return (i);
	}
      i++;
    }
  return (-1);
}
