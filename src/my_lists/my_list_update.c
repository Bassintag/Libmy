/*
** my_list_update.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov 30 09:35:24 2016 Antoine Stempfer
** Last update Sun Feb 26 15:48:57 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

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
