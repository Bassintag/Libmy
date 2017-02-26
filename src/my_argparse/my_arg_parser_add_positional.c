/*
** my_arg_parser_add_required.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:47:31 2017 Antoine Stempfer
** Last update Sun Feb 26 17:39:25 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

void	my_arg_parser_add_positional(t_arg_parser *parser,
				     char *id, int nargs,
				     int (*callback)(t_arg *,
						     t_list *,
						     void *))
{
  t_arg	*arg;

  arg = malloc(sizeof(t_arg));
  arg->identifier = my_strcat("-", id);
  arg->separated = B_TRUE;
  arg->required = B_FALSE;
  arg->nargs = nargs;
  arg->callback = callback;
  my_list_append(&parser->positional, arg);
}
