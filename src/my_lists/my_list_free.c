/*
** my_list_free.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Tue Nov 22 21:48:26 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"

void		my_list_free(t_list **list)
{
  t_list	*current;
  t_list	*next;

  current = *list;
  while (current)
    {
      next = current->next;
      free(current);
      current = next;
    }
}
