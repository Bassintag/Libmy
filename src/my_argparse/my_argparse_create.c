/*
** my_arg_parser_create.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:38:26 2017 Antoine Stempfer
** Last update Thu Mar  2 00:23:47 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_arg_parser	*my_argparse_create(void *main, char *description, char *help)
{
  t_arg_parser	*parser;

  parser = malloc(sizeof(t_arg_parser));
  parser->showed_help = B_FALSE;
  parser->help_id = help;
  parser->description = description;
  parser->required = NULL;
  parser->optional = NULL;
  parser->main = main;
  return (parser);
}
