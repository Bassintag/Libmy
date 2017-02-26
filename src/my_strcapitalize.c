/*
** my_strcapitalize.c for my_strcapitalize in /home/antoine.stempfer/delivery/CPool_Day06
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Oct 10 11:06:28 2016 Antoine Stempfer
** Last update Tue Jan 10 15:56:28 2017 Antoine Stempfer
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0')
    {
      if (my_char_islower(str[index]))
	if (index == 0 || !my_char_isalpha(str[index - 1]))
	  str[index] += 'a' - 'A';
      index++;
    }
  return (str);
}
