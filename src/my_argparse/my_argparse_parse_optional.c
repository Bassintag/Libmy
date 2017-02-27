/*
** my_parse_positional.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_argparse
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:52:19 2017 Antoine Stempfer
** Last update Mon Feb 27 15:45:38 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static int	my_argparse_parse_shorthand(t_arg *arg,	t_list **args,
					    void *main)
{
  t_list	*sublist;

  if (arg->shorthand && !my_strcmp(arg->shorthand, my_list_get(*args, 0)))
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
  return (STATUS_FAILURE);
}

static int	_my_argparse_parse_optional(t_arg *arg, char *id,
					    t_list *args, void *main)
{
  if (my_strcmp(id, arg->identifier) != 0)
    return (STATUS_FAILURE);
  if (my_list_len(args) != arg->nargs)
    return (STATUS_FAILURE);
  if (arg->callback(arg, args, main) != STATUS_SUCCESS)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}

static int	my_argparse_free_tmp(t_list **args_l, char **split,
				     t_list **args)
{
  my_list_destroy(args_l);
  my_free_strtab(split);
  my_list_nfree(args, 1);
  return (STATUS_SUCCESS);
}

int		my_argparse_parse_optional(t_arg_parser *parser,
					   t_list **args, void *main)
{
  t_arg		*arg;
  t_list	*args_l;
  char		**split;

  my_list_next(NULL);
  while ((arg = my_list_next(parser->optional)) != NULL)
    {
      if (my_argparse_parse_shorthand(arg, args, main) == STATUS_SUCCESS)
	return (STATUS_SUCCESS);
      split = my_split((char *)my_list_get(*args, 0), '=');
      if (my_strtablen(split) == 2)
	{
	  args_l = my_list_from_strtab(my_split(split[1], ','));
	  if (_my_argparse_parse_optional(arg, split[0], args_l, main) ==
	      STATUS_SUCCESS)
	    return (my_argparse_free_tmp(&args_l, split, args));
	  my_list_destroy(&args_l);
	}
      my_free_strtab(split);
    }
  return (STATUS_FAILURE);
}

