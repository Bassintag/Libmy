/*
** my_free_tab.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar  2 00:14:17 2017 Antoine Stempfer
** Last update Thu Mar  2 00:16:21 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_free_tab(void **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (STATUS_SUCCESS);
}
