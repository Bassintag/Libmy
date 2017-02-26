/*
** my_parse_args.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 15:25:04 2017 Antoine Stempfer
** Last update Sun Feb 26 15:43:06 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int		my_parse_args(t_arg_parser *parser, int ac,
			      char **av, void *main)
{
  t_list	*args;
  int		i;

  if (my_args_validate(parser) != STATUS_SUCCESS)
    return (STATUS_FAILURE);
  i = 1;
  args = NULL;
  while (i < ac)
    {
      my_list_append(&args, av[i]);
      i++;
    }
  while (my_list_len(args) > 0)
    {
      if (my_parse_required(parser, args, main) == STATUS_FAILURE)
	  if (my_parse_optional(parser, args, main) == STATUS_FAILURE)
	    return (STATUS_FAILURE);
    }
  return (my_list_len(parser->required) ? STATUS_FAILURE : STATUS_SUCCESS);
}
