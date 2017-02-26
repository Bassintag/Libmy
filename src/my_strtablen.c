/*
** my_tab_len.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:24:30 2016 Antoine Stempfer
** Last update Mon Dec 12 13:26:16 2016 Antoine Stempfer
*/

#include "my.h"

int	my_strtablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
