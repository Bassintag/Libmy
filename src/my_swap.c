/*
** my_swap.c for libmy in /home/bassintag/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 15:58:06 2017 Antoine Stempfer
** Last update Tue Jan 10 16:01:09 2017 Antoine Stempfer
*/

#include "my.h"

void	my_swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
