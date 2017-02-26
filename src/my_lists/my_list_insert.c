/*
** my_list_insert.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Sun Feb 26 15:47:31 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		my_list_insert(t_list **list, void *value, int pos)
{
  t_list	*new;
  t_list	*current;
  t_list	*next;
  int		i;

  new = malloc(sizeof(t_list));
  new->value = value;
  current = *list;
  i = 0;
  while (i++ < pos)
    current = current->next;
  next = current->next;
  current->next = new;
  new->next = next;
  if (pos == 0)
    *list = new;
}
