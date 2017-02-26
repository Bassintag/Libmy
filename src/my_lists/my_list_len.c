/*
** my_list_len.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Sun Feb 26 15:47:54 2017 Antoine Stempfer
*/

#include "my.h"
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
