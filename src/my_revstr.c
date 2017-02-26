/*
** my_revstr.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:51:43 2017 Antoine Stempfer
** Last update Tue Jan 10 15:56:12 2017 Antoine Stempfer
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	len;
  int	i;
  char	c;

  i = 0;
  len = my_strlen(str);
  while (i * 2 < len)
    {
      c = str[i];
      str[i] = str[len - 1 - i];
      str[len - 1 - i] = c;
      i++;
    }
  return (str);
}
