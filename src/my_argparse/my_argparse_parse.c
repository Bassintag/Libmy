/*
** my_parse_args.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 15:25:04 2017 Antoine Stempfer
** Last update Mon Feb 27 20:30:49 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "argparse.h"

static int	_my_argparse_parse(t_arg_parser *parser, t_list **args,
				   t_list **required, void *main)
{
  while (my_list_len(*args) > 0)
    {
      if (my_argparse_parse_optional(parser, args, main) == STATUS_FAILURE)
	if (my_argparse_parse_required(required, args, main) ==
	    STATUS_FAILURE)
	  {
	    my_list_free(args);
	    my_list_free(required);
	    return (STATUS_FAILURE);
	  }
    }
  return (STATUS_SUCCESS);
}

int		my_argparse_parse(t_arg_parser *parser, int ac,
				  char **av, void *main)
{
  t_list	*args;
  t_list	*required;
  int		i;

  if (parser->help_id && ac == 2 && my_strcmp(parser->help_id, av[1]) == 0)
    return (my_argparse_show_help(av[0], parser));
  i = 1;
  args = NULL;
  required = my_list_clone(parser->required);
  while (i < ac)
    {
      my_list_append(&args, av[i]);
      i++;
    }
  if (_my_argparse_parse(parser, &args, &required, main))
    return (STATUS_FAILURE);
  return (my_list_len(required) ? STATUS_FAILURE : STATUS_SUCCESS);
}
