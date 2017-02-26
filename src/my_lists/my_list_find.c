/*
** my_list_find.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sat Jan  7 16:49:56 2017 Antoine Stempfer
** Last update Sat Jan  7 17:12:06 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

void		*my_list_find(t_list *list, void *comp,
			      int (*f)(void *, void *))
{
  t_list	*item;

  item = list;
  while (item != NULL)
    {
      if (f(item->value, comp) == 0)
	return (item->value);
      item = item->next;
    }
  return (NULL);
}
