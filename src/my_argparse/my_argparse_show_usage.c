/*
** my_argparse_show_usage.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 21:02:28 2017 Antoine Stempfer
** Last update Mon Feb 27 21:02:38 2017 Antoine Stempfer
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
