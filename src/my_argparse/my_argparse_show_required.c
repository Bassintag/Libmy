/*
** my_argparse_show_required.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 21:02:58 2017 Antoine Stempfer
** Last update Mon Feb 27 21:03:17 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_argparse_show_required(t_arg_parser *parser)
{
  char	*args;
  t_arg	*arg;

  args = my_strdup("Arguments:\n");
  my_list_next(NULL);
  while ((arg = my_list_next(parser->required)) != NULL)
    {
      args = my_strappend(args, "\t");
      args = my_strappend(args, arg->identifier);
      args = my_strappend(args, "\n");
    }
  my_putstr(args);
  free(args);
  return (STATUS_SUCCESS);
}

