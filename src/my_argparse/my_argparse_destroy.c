/*
** my_argparse_destroy.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 21:24:54 2017 Antoine Stempfer
** Last update Mon Feb 27 21:28:57 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static void	my_argparse_free_arg(t_arg *arg)
{
  free(arg->identifier);
  if (arg->shorthand != NULL)
    free(arg->shorthand);
  free(arg);
}

void	my_argparse_destroy(t_arg_parser *parser)
{
  while (parser->required != NULL)
    my_argparse_free_arg(my_list_delete(&parser->required, 0));
  while (parser->optional != NULL)
    my_argparse_free_arg(my_list_delete(&parser->optional, 0));
  free(parser);
}
