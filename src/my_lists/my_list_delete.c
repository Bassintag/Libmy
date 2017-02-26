/*
** my_list_delete.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Tue Nov 22 21:58:18 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

void		*my_list_delete(t_list **list, int pos)
{
  t_list	*current;
  t_list	*previous;
  void		*value;
  int		i;

  current = *list;
  previous = NULL;
  i = 0;
  while (i++ < pos)
    {
      previous = current;
      current = current->next;
    }
  if (previous != NULL)
    previous->next = current->next;
  value = current->value;
  if (pos == 0)
    *list = current->next;
  free(current);
  return (value);
}
