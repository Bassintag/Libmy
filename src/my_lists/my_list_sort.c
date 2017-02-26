/*
** my_list_sort.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 22:03:15 2016 Antoine Stempfer
** Last update Fri Dec  2 16:25:03 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

static void	swap_elements(t_list **list, t_list *prev,
			      t_list *cur, t_list *next)
{
  cur->next = next->next;
  next->next = cur;
  if (prev)
    prev->next = next;
  else
    *list = next;
}

void		my_list_sort(t_list **list, int (*comp)(void *, void *), int e)
{
  t_list	*cur;
  t_list	*prev;
  t_list	*next;
  char		swapped;

  swapped = 1;
  while (swapped)
    {
      prev = NULL;
      cur = *list;
      swapped = 0;
      while (cur->next)
	{
	  next = cur->next;
	  if ((*comp)((cur->value), (next->value)) == e)
	    {
	      swap_elements(list, prev, cur, next);
	      swapped = 1;
	    }
	  prev = cur;
	  cur = next;
	}
    }
}
