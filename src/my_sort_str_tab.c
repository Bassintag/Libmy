/*
** my_sort_str_tab.c for libmy in /home/antoine.stempfer/delivery/CPool_Day07/bckp
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Oct 11 11:39:28 2016 Antoine Stempfer
** Last update Tue Jan 10 15:55:42 2017 Antoine Stempfer
*/
#include "my.h"

static void	_my_swap_str(char **a, char **b)
{
  char		*c;

  c = *a;
  *a = *b;
  *b = c;
}

void	my_sort_str_tab(char *tab[], int size)
{
  char	swapped;
  int	index;

  swapped = 1;
  while (swapped)
    {
      swapped = 0;
      index = 0;
      while (++index < size)
	{
	  if (my_strcmp(tab[index - 1], tab[index]) == -1)
	    {
	      _my_swap_str(&tab[index - 1], &tab[index]);
	      swapped = 1;
	    }
	}
    }
}
