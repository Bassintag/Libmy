/*
** my_argparse_show_options.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Feb 27 21:01:31 2017 Antoine Stempfer
** Last update Wed Mar  1 17:04:46 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static int	my_argparse_append_params(t_arg *arg, char **options)
{
  int		i;
  char		tmp[2];
  char		*desc;

  if (arg->nargs > 0)
    {
      *options = my_strappend(*options, "={");
      i = 0;
      tmp[1] = '\0';
      while (i < arg->nargs)
	{
	  if ((desc = my_list_get(arg->argdesc, i)) != NULL)
	    *options = my_strappend(*options, desc);
	  else
	    {
	      tmp[0] = 'A' + i;
	      *options = my_strappend(*options, tmp);
	    }
	  i++;
	  if (i < arg->nargs)
	    *options = my_strappend(*options, ",");
	}
      *options = my_strappend(*options, "}");
    }
  return (STATUS_SUCCESS);
}

static int	my_argparse_calc_padding(t_arg_parser *parser)
{
  int		res;
  int		tmp;
  t_arg		*arg;

  if (parser->help_id != NULL)
    res = my_strlen(parser->help_id) + 1;
  else
    res = 1;
  my_list_next(NULL);
  while ((arg = my_list_next(parser->optional)) != NULL)
    {
      tmp = my_strlen(arg->identifier) + 1;
      if (arg->shorthand != NULL)
	tmp += my_strlen(arg->shorthand) + 1;
      if (arg->nargs > 0)
	tmp += 3;
      tmp += MAX(0, arg->nargs * 2 - 1);
      if (tmp > res)
	res = tmp;
    }
  return (res);
}

static int	my_argparse_add_padding(t_arg *option, char **options,
				       int padding)
{
  int		len;
  char		*tmp;

  len = padding - my_strlen(option->identifier);
  if (option->shorthand != NULL)
    len -= my_strlen(option->shorthand) + 1;
  if (option->nargs > 0)
    len -= 3;
  len -= MAX(0, option->nargs * 2 - 1);
  tmp = malloc(sizeof(char) * len + 1);
  tmp[len] = '\0';
  while (--len >= 0)
    tmp[len] = ' ';
  *options = my_strappend(*options, tmp);
  free(tmp);
  return (STATUS_SUCCESS);
}

static int	my_argparse_append_option(t_arg *option, char **options,
					  int padding)
{
  *options = my_strappend(*options, "   ");
  if (option->shorthand != NULL)
    {
      *options = my_strappend(*options, option->shorthand);
      *options = my_strappend(*options, " ");
    }
  *options = my_strappend(*options, option->identifier);
  my_argparse_append_params(option, options);
  if (option->description != NULL)
    {
      my_argparse_add_padding(option, options, padding);
      *options = my_strappend(*options, option->description);
    }
  *options = my_strappend(*options, "\n");
  return (STATUS_SUCCESS);
}

int	my_argparse_show_options(t_arg_parser *parser)
{
  char	*options;
  char	*tmp;
  t_arg	*option;
  int	padding;
  int	len;

  options = my_strcat("Options:\n   ", parser->help_id);
  padding = my_argparse_calc_padding(parser);
  len = padding - my_strlen(parser->help_id);
  tmp = malloc(sizeof(char) * len + 1);
  tmp[len] = '\0';
  while (--len >= 0)
    tmp[len] = ' ';
  options = my_strappend(options, tmp);
  free(tmp);
  options = my_strappend(options, "Display this help\n");
  my_list_next(NULL);
  while ((option = my_list_next(parser->optional)) != NULL)
    my_argparse_append_option(option, &options, padding);
  my_putstr(options);
  free(options);
  return (STATUS_SUCCESS);
}
