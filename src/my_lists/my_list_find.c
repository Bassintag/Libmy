/*
** my_list_find.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sat Jan  7 16:49:56 2017 Antoine Stempfer
** Last update Sun Feb 26 15:46:59 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

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
