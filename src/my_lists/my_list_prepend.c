/*
** my_list_prepend.c for libmylists in /home/bassintag/delivery/Libmylists/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 22 21:30:42 2016 Antoine Stempfer
** Last update Sun Feb 26 15:48:06 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		my_list_prepend(t_list **list, void *value)
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  new->value = value;
  new->next = *list;
  *list = new;
}
