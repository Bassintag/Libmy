/*
** my_list_sublist.c for libmylist in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:16:46 2017 Antoine Stempfer
** Last update Sun Feb 26 16:24:26 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_list		*my_list_sublist(t_list *source, int begin, int len)
{
  int		i;
  t_list	*res;
  void		*item;

  res = NULL;
  i = 0;
  while (i < len)
    {
      if ((item = my_list_get(source, begin + i)) == NULL)
	{
	  my_list_free(&res);
	  return (NULL);
	}
      my_list_append(&res, item);
      i++;
    }
  return (res);
}
