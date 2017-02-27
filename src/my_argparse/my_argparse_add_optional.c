/*
** my_argparse_add_optional.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:47:31 2017 Antoine Stempfer
** Last update Mon Feb 27 20:39:29 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_arg	*my_argparse_add_optional(t_arg_parser *parser,
				   char *id, int nargs,
				   int (*callback)(t_arg *,
						   t_list *,
						   void *))
{
  t_arg	*arg;

  arg = malloc(sizeof(t_arg));
  arg->identifier = my_strcat("--", id);
  arg->description = NULL;
  arg->shorthand = NULL;
  arg->required = B_FALSE;
  arg->nargs = nargs;
  arg->callback = callback;
  my_list_append(&parser->optional, arg);
  return (arg);
}

t_arg	*my_argparse_add_optional_shorthand(t_arg_parser *parser,
					    char *id, int nargs,
					    int (*callback)(t_arg *,
							    t_list *,
							    void *))
{
  t_arg	*arg;
  char	**split;
  int	i;

  arg = my_argparse_add_optional(parser, id, nargs, callback);
  split = my_split(id, '-');
  i = 0;
  arg->shorthand = malloc(sizeof(char) * (my_strtablen(split) + 2));
  arg->shorthand[0] = '-';
  while (split[i] != NULL)
    {
      arg->shorthand[i + 1] = split[i][0];
      i++;
    }
  arg->shorthand[i + 1] = '\0';
  my_free_strtab(split);
  return (arg);
}
