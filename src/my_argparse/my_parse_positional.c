/*
** my_parse_positional.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_argparse
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:52:19 2017 Antoine Stempfer
** Last update Sun Feb 26 17:52:41 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int		my_parse_positional(t_arg_parser *parser, t_list **args,
				    void *main)
{
  t_arg		*arg;
  t_list	*sublist;

  my_list_next(NULL);
  while ((arg = my_list_next(parser->positional)) != NULL)
    {
      if (my_strcmp(arg->identifier, my_list_get(*args, 0)) == 0)
	{
	  if ((sublist = my_list_sublist(*args, 1, arg->nargs)) == NULL
	      && arg->nargs > 0)
	    return (STATUS_FAILURE);
	  if (arg->callback(arg, sublist, main) != STATUS_SUCCESS)
	    {
	      if (sublist != NULL)
		my_list_free(&sublist);
	      return (STATUS_FAILURE);
	    }
	  my_list_nfree(args, arg->nargs + 1);
	  my_list_free(&sublist);
	  return (STATUS_SUCCESS);
	}
    }
  return (STATUS_FAILURE);
}

