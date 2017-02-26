/*
** my_list_rotate.c for libmylists in /home/bassintag/delivery/Libmylists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 15:17:34 2016 Antoine Stempfer
** Last update Sun Feb 26 15:48:36 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		my_list_rotate(t_list **list)
{
  t_list	*last;
  t_list	*current;

  if (*list == NULL || (*list)->next == NULL)
    return ;
  last = *list;
  while (last->next != NULL)
    last = last->next;
  last->next = (*list);
  current = *list;
  *list = (*list)->next;
  current->next = NULL;
}
