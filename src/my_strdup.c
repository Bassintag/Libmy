/*
** my_strdup.c for libmy in /home/antoine.stempfer/delivery/CPool_Day08
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Oct 12 07:50:15 2016 Antoine Stempfer
** Last update Tue Jan 10 15:20:40 2017 Antoine Stempfer
*/

#include "my.h"
#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*copy;
  int	length;

  length = my_strlen(str);
  copy = malloc((1 + length) * sizeof(char));
  my_strcpy(copy, str);
  copy[length] = '\0';
  return (copy);
}
