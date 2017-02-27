/*
** my_list_from_strtab.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_lists
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 15:03:12 2017 Antoine Stempfer
** Last update Mon Feb 27 15:39:07 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_list		*my_list_from_strtab(char **values)
{
  int		i;
  t_list	*res;

  i = 0;
  res = NULL;
  while (values[i] != NULL)
    {
      my_list_append(&res, values[i]);
      i++;
    }
  return (res);
}
