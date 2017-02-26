/*
** my_char_isnum.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:33:18 2017 Antoine Stempfer
** Last update Tue Jan 10 15:29:17 2017 Antoine Stempfer
*/

#include "my.h"

int	my_char_isnum(char c)
{
  return (c >= '0' && c <= '9');
}
