/*
** my_argparse_show_help.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 15:48:26 2017 Antoine Stempfer
** Last update Mon Feb 27 20:43:19 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

int	my_argparse_show_usage(char *prog, t_arg_parser *parser)
{
  char	*usage;
  t_arg	*required;

  usage = my_strdup(prog);
  my_list_next(NULL);
  while ((required = my_list_next(parser->required)) != NULL)
    usage = my_strappend(my_strappend(usage, " "), required->identifier);
  if (parser->optional != NULL)
    usage = my_strappend(usage, " [options]");
  my_printf("Usage: %s\n", usage);
  free(usage);
  return (STATUS_SUCCESS);
}

int	my_argparse_show_options(t_arg_parser *parser)
{
  char	*options;
  t_arg	*option;

  options = my_strdup("Options:\n");
  my_list_next(NULL);
  while ((option = my_list_next(parser->optional)) != NULL)
    {
      options = my_strappend(options, "\t");
      if (option->shorthand != NULL)
	{
	  options = my_strappend(options, option->shorthand);
	  options = my_strappend(options, " ");
	}
      options = my_strappend(options, option->identifier);
      if (option->description != NULL)
	options = my_strappend(my_strappend(options, "\t"),
			       option->description);
      options = my_strappend(options, "\n");
    }
  my_putstr(options);
  free(options);
  return (STATUS_SUCCESS);
}

int	my_argparse_show_required(t_arg_parser *parser)
{
  char	*args;
  t_arg	*arg;

  args = my_strdup("Arguments:\n");
  my_list_next(NULL);
  while ((arg = my_list_next(parser->required)) != NULL)
    {
      args = my_strappend(args, "\t");
      args = my_strappend(args, arg->identifier);
      args = my_strappend(args, "\n");
    }
  my_putstr(args);
  free(args);
  return (STATUS_SUCCESS);
}

int	my_argparse_show_help(char *prog, t_arg_parser *parser)
{
  my_argparse_show_usage(prog, parser);
  if (parser->description != NULL)
    my_printf("Description:\n\t%s", parser->description);
  if (parser->required != NULL)
    my_argparse_show_required(parser);
  if (parser->optional != NULL)
    my_argparse_show_options(parser);
  return (STATUS_SUCCESS);
}
