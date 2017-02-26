/*
** my_list_nfree.c for libmylist in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:29:39 2017 Antoine Stempfer
** Last update Sun Feb 26 17:30:40 2017 Antoine Stempfer
*/

#include "my.h"

void	my_list_nfree(t_list **list, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      my_list_delete(list, 0);
      i++;
    }
}
