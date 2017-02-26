/*
** my_strcmp.c for my_strcmp in /home/antoine.stempfer/delivery/CPool_Day06
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Oct 10 10:21:54 2016 Antoine Stempfer
** Last update Tue Jan  3 10:11:56 2017 Antoine Stempfer
*/

#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
  int	index;

  index = 0;
  while (str1[index] != '\0' && str2[index] != '\0')
    {
      if (str1[index] < str2[index])
	return (-1);
      if (str1[index] > str2[index])
	return (1);
      index++;
    }
  if (my_strlen(str1) < my_strlen(str2))
    return (-1);
  if (my_strlen(str1) > my_strlen(str2))
    return (1);
  return (0);
}
