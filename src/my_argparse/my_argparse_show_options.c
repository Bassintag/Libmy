/*
** _my_argparse_show_options.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Mar  1 17:11:13 2017 Antoine Stempfer
** Last update Mon Mar  6 15:38:52 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static char    	*my_argparse_get_line(t_arg *arg)
{
  char		*res;
  char		*opt;
  int		i;

  if (arg->shorthand)
    res = my_strappend(my_strcat("   ", arg->shorthand), " ");
  else
    res = my_strdup("   ");
  res = my_strappend(res, arg->identifier);
  if (arg->nargs > 0)
    {
      res = my_strappend(res, "={");
      i = 0;
      while (i < arg->nargs)
	{
	  if ((opt = my_list_get(arg->argdesc, i)) != NULL)
	    res = my_strappend(res, opt);
	  else
	    res = my_strappendchar(res, 'a' + i);
	  if (++i < arg->nargs)
	    res = my_strappend(res, ",");
	}
      res = my_strappend(res, "}");
    }
  return (res);
}

static int     	my_argparse_get_padding(t_list *lines)
{
  int		res;
  char		*line;

  res = 0;
  my_list_next(NULL);
  while ((line = my_list_next(lines)))
    res = MAX(res, my_strlen(line) + 1);
  return (res);
}

static void	my_argparse_show_line(t_arg *arg, char *line, int padding)
{
  int		i;

  my_putstr(line);
  i = my_strlen(line);
  while (i < padding)
    {
      my_putchar(' ');
      i++;
    }
  if (arg == NULL)
    my_putstr("Display this help\n");
  else if (arg->description != NULL)
    my_printf("%s\n", arg->description);
}

int		my_argparse_show_options(t_arg_parser *parser)
{
  t_list	*lines;
  t_arg		*option;
  int		padding;
  int		i;

  lines = NULL;
  my_putstr("Options:\n");
  my_list_append(&lines, my_strdup("   --help"));
  my_list_next(NULL);
  while ((option = my_list_next(parser->optional)))
    my_list_append(&lines, my_argparse_get_line(option));
  padding = my_argparse_get_padding(lines);
  i = 0;
  my_argparse_show_line(NULL, my_list_get(lines, i), padding);
  while ((option = my_list_get(parser->optional, i)) != NULL)
    {
      my_argparse_show_line(option, my_list_get(lines, i + 1), padding);
      i++;
    }
  my_list_destroy(&lines);
  return (STATUS_SUCCESS);
}
