/*
** my_list_destroy.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 15:26:51 2017 Antoine Stempfer
** Last update Mon Feb 27 15:28:58 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void	my_list_destroy(t_list **list)
{
  while (my_list_get(*list, 0) != NULL)
    free(my_list_delete(list, 0));
  *list = NULL;
}
