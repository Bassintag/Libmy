/*
** my_parse_args.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 15:25:04 2017 Antoine Stempfer
** Last update Sun Feb 26 17:53:16 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "argparse.h"

int		my_parse_args(t_arg_parser *parser, int ac,
			      char **av, void *main)
{
  t_list	*args;
  t_list	*required;
  int		i;

  if (my_args_validate(parser) != STATUS_SUCCESS)
    return (STATUS_FAILURE);
  i = 1;
  args = NULL;
  required = my_list_clone(parser->required);
  while (i < ac)
    {
      my_list_append(&args, av[i]);
      i++;
    }
  while (my_list_len(args) > 0)
    {
      if (my_parse_positional(parser, &args, main) == STATUS_FAILURE)
	if (my_parse_required(&required, &args, main) == STATUS_FAILURE)
	  {
	    my_list_free(&args);
	    my_list_free(&required);
	    return (STATUS_FAILURE);
	  }
    }
  return (my_list_len(required) ? STATUS_FAILURE : STATUS_SUCCESS);
}
