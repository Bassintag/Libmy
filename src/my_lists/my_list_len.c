/*
** my_list_len.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Tue Nov 22 21:48:49 2016 Antoine Stempfer
*/

#include "mylists.h"
#include <stdlib.h>

int		my_list_len(t_list *list)
{
  t_list	*current;
  int		len;

  current = list;
  len = 0;
  while (current != NULL)
    {
      len++;
      current = current->next;
    }
  return (len);
}
