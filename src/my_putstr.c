/*
** my_putstr.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:44:14 2017 Antoine Stempfer
** Last update Tue Jan 10 14:51:17 2017 Antoine Stempfer
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
