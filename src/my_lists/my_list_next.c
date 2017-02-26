/*
** my_list_next.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_lists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:07:58 2017 Antoine Stempfer
** Last update Sun Feb 26 17:22:13 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void		*my_list_next(t_list *list)
{
  static t_list	*current = NULL;
  static int	index;
  void		*res;

  if (current != list)
    {
      current = list;
      index = 0;
    }
  if (list == NULL)
    return (NULL);
  res = my_list_get(list, index);
  index++;
  return (res);
}
