/*
** my_char_islower.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:33:18 2017 Antoine Stempfer
** Last update Tue Jan 10 15:29:05 2017 Antoine Stempfer
*/

#include "my.h"

int	my_char_islower(char c)
{
  return (c >= 'a' && c <= 'z');
}
