/*
** my_list_get.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Wed Dec 14 20:24:53 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

void		*my_list_get(t_list *list, int pos)
{
  t_list	*current;
  int		i;

  current = list;
  i = 0;
  while (i++ < pos && current != NULL)
    current = current->next;
  return (current == NULL ? NULL : current->value);
}
