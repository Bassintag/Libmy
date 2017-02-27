/*
** my_arg_parser_add_required.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:47:31 2017 Antoine Stempfer
** Last update Mon Feb 27 20:38:58 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_arg	*my_argparse_add_required(t_arg_parser *parser, char *name,
				 int (*callback)(t_arg *, t_list *, void *))
{
  t_arg	*arg;

  arg = malloc(sizeof(t_arg));
  arg->identifier = name;
  arg->description = NULL;
  arg->shorthand = NULL;
  arg->required = B_TRUE;
  arg->nargs = 1;
  arg->callback = callback;
  my_list_append(&parser->required, arg);
  return (arg);
}
