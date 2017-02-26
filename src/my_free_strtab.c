/*
** my_free_strtab.c for libmyio in /home/bassintag/delivery/Libmyio/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Nov 17 17:42:02 2016 Antoine Stempfer
** Last update Tue Jan 10 14:33:04 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_free_strtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (0);
}
