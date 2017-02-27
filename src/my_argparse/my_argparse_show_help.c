/*
** my_argparse_show_help.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 15:48:26 2017 Antoine Stempfer
** Last update Mon Feb 27 21:03:20 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_argparse_show_help(char *prog, t_arg_parser *parser)
{
  my_argparse_show_usage(prog, parser);
  if (parser->description != NULL)
    my_printf("Description:\n\t%s", parser->description);
  if (parser->required != NULL)
    my_argparse_show_required(parser);
  my_argparse_show_options(parser);
  return (STATUS_SUCCESS);
}
