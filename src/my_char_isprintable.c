/*
** my_char_isalpha.c for libmy in /home/bassintag/delivery/Libmy_new/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 14:33:18 2017 Antoine Stempfer
** Last update Tue Jan 10 15:29:30 2017 Antoine Stempfer
*/

#include "my.h"

int	my_char_isprintable(char c)
{
  return (c >= 32 && c <= 126);
}
