/*
** my_list_remove.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Sun Feb 26 15:48:15 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		my_list_remove(t_list **list, void *value)
{
  t_list	*current;
  t_list	*previous;

  current = *list;
  previous = NULL;
  while (current != NULL && current->value != value)
    {
      previous = current;
      current = current->next;
    }
  if (current == NULL)
    return ;
  if (previous != NULL)
    previous->next = current->next;
  else
    *list = current->next;
  free(current);
}
