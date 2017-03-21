/*
** my_strncmp.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Mar  7 10:11:11 2017 Antoine Stempfer
** Last update Tue Mar  7 10:15:04 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_strncmp(char *str1, char *str2, int len)
{
  int	index;

  index = 0;
  while (str1[index] != '\0' && str2[index] != '\0' && index < len)
    {
      if (str1[index] < str2[index])
	return (-1);
      if (str1[index] > str2[index])
	return (1);
      index++;
    }
  if (index < len)
    {
      if (str1[index] < str2[index])
	return (-1);
      if (str1[index] > str2[index])
	return (1);
    }
  return (0);
}
