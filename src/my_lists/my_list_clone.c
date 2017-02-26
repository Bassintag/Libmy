/*
** my_list_clone.c for libmylists in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 15:53:29 2017 Antoine Stempfer
** Last update Sun Feb 26 16:56:18 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_list		*my_list_clone(t_list *source)
{
  int		i;
  void		*item;
  t_list	*res;

  i = 0;
  res = NULL;
  while ((item = my_list_get(source, i)) != NULL)
    {
      my_list_append(&res, item);
      i++;
    }
  return (res);
}
