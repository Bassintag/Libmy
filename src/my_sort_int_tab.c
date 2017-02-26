/*
** my_sort_int_tab.c for my_sort_int_tab in /home/antoine.stempfer/delivery/CPool_Day04
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Oct  6 16:30:28 2016 Antoine Stempfer
** Last update Thu Oct 13 09:00:22 2016 Antoine Stempfer
*/
#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  char	swapped;
  int	iterator;

  swapped = 1;
  while (swapped)
    {
      swapped = 0;
      iterator = 1;
      while (iterator < size)
	{
	  if (*(tab + iterator - 1) > *(tab + iterator))
	    {
	      my_swap(tab + iterator - 1, tab + iterator);
	      swapped = 1;
	    }
	  iterator++;
	}
    }
}
