/*
** my_arg_parser_create.c for libmy in /home/antoine.stempfer/delivery/Libmy/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 16:38:26 2017 Antoine Stempfer
** Last update Sun Feb 26 17:05:12 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

t_arg_parser	*my_arg_parser_create(void *main)
{
  t_arg_parser	*parser;

  parser = malloc(sizeof(t_arg_parser));
  parser->required = NULL;
  parser->optional = NULL;
  parser->positional = NULL;
  parser->main = main;
  return (parser);
}
