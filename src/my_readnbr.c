/*
** my_getnbr.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov  9 18:14:43 2016 Antoine Stempfer
** Last update Tue Jan 10 15:57:16 2017 Antoine Stempfer
*/

#include "my.h"

int	my_readnbr(char **str)
{
  int	i;

  i = 0;
  while (**str >= '0' && **str <= '9')
    {
      i *= 10;
      i += **str - '0';
      (*str)++;
    }
  return (i);
}
