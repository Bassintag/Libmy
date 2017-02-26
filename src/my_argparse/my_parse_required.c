/*
** my_parse_required.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_argparse
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:49:20 2017 Antoine Stempfer
** Last update Sun Feb 26 17:51:26 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "argparse.h"

int		my_parse_required(t_list **required, t_list **args, void *main)
{
  t_arg		*arg;
  t_list	*sublist;

  arg = my_list_get(*required, 0);
  if (arg == NULL)
    return (STATUS_FAILURE);
  if ((sublist = my_list_sublist(*args, 0, 1)) == NULL)
    return (STATUS_FAILURE);
  if (arg->callback(arg, sublist, main) != STATUS_SUCCESS)
    {
      my_list_free(&sublist);
      return (STATUS_FAILURE);
    }
  my_list_delete(required, 0);
  my_list_delete(args, 0);
  my_list_free(&sublist);
  return (STATUS_SUCCESS);
}

