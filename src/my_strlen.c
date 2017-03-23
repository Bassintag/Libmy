/*
** my_strlen.c for my_strlen in /home/antoine.stempfer/delivery/CPool_Day04
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Oct  6 08:35:11 2016 Antoine Stempfer
** Last update Thu Mar 23 17:02:56 2017 Antoine Stempfer
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	len;

  if (str == NULL)
    return (0);
  len = 0;
  while (*str != '\0')
    {
      str += 1;
      len += 1;
    }
  return (len);
}
