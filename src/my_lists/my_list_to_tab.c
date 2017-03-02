/*
** my_list_to_tab.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Feb 28 14:08:24 2017 Antoine Stempfer
** Last update Tue Feb 28 14:12:33 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void	**my_list_to_tab(t_list *list)
{
  void	**res;
  void	*item;
  int	i;

  res = malloc(sizeof(void *) * (my_list_len(list) + 1));
  i = 0;
  while ((item = my_list_get(list, i)) != NULL)
    {
      res[i] = item;
      i++;
    }
  res[i] = NULL;
  return (res);
}
