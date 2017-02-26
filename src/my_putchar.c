/*
** my_putchar.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:44:14 2017 Antoine Stempfer
** Last update Tue Jan 10 14:45:55 2017 Antoine Stempfer
*/

#include <unistd.h>
#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
