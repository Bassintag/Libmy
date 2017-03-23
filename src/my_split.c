/*
** my_split.c for libmyio in /home/bassintag/delivery/Libmyio
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Nov 17 17:16:09 2016 Antoine Stempfer
** Last update Wed Mar 22 14:23:00 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static int	count_occurrences(char *buffer, char c)
{
  int		occurrences;
  int		i;

  occurrences = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] != c && (i == 0 || buffer[i - 1] == c))
	occurrences += 1;
      i++;
    }
  return (occurrences);
}

static int	count_chars(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != c)
    i++;
  return (i);
}

char	**my_split(char *str, char c)
{
  char	**res;
  int	occ;
  int	i;
  int	j;
  int	k;

  occ = count_occurrences(str, c);
  res = malloc(sizeof(char *) * MAX(occ + 1, 2));
  j = 0;
  i = 0;
  while (str[i] != '\0' && j < occ)
    {
      while (str[i] == c)
	i++;
      res[j] = malloc(sizeof(char *) * (count_chars(&str[i], c)));
      k = 0;
      while (str[i] != '\0' && str[i] != c)
	res[j][k++] = str[i++];
      res[j++][k] = '\0';
    }
  if (j == 0)
    res[j++] = my_strdup("");
  res[j] = NULL;
  return (occ == 1 && res[0][0] == '\0' ? NULL : res);
}
