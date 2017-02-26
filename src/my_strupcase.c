/*
** my_strupcase.c for my_strupcase in /home/antoine.stempfer/delivery/CPool_Day06
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Oct 10 11:06:28 2016 Antoine Stempfer
** Last update Tue Jan 10 15:53:36 2017 Antoine Stempfer
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0')
    {
      if (my_char_islower(str[index]))
	str[index] += 'A' - 'a';
      index++;
    }
  return (str);
}
