/*
** my_list_update.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov 30 09:35:24 2016 Antoine Stempfer
** Last update Wed Nov 30 09:36:51 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

void		*my_list_update(t_list *list, int pos, void *value)
{
  t_list	*current;
  int		i;
  void		*tmp;

  current = list;
  i = 0;
  while (i++ < pos)
    current = current->next;
  tmp = current->value;
  current->value = value;
  return (tmp);
}
