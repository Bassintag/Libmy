/*
** my_strlowcase.c for my_strlowcase in /home/antoine.stempfer/delivery/CPool_Day06
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Oct 10 11:06:28 2016 Antoine Stempfer
** Last update Tue Jan 10 15:54:15 2017 Antoine Stempfer
*/

#include "my.h"

char	*my_strlowcase(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0')
    {
      if (my_char_isupper(str[index]))
	str[index] += 'a' - 'A';
      index++;
    }
  return (str);
}
