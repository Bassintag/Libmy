/*
** my_parse_args.c for libmy in /home/antoine.stempfer/delivery/Libmy/src/my_argparse
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Feb 22 14:36:38 2017 Antoine Stempfer
** Last update Wed Feb 22 16:41:46 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"

static char	**my_read_nargs(int i, int nb, char **av)
{
  char		**res;
  int		j;

  res = malloc(sizeof(char *) * (nb + 1));
  res[nb] = NULL;
  j = 0;
  while (j < nb)
    {
      res[j] = av[i + j];
      j++;
    }
  return (res);
}

static int	parse_separated(t_arg *param, int *i, void *main, char **av)
{
  char		**args;

  args = my_read_nargs(*i + 1, param->nargs, av);
  if (param->callback(param, args, main))
    return (STATUS_FAILURE);
  free(args);
  *i += param->nargs;
  return (STATUS_SUCCESS);
}

static int	parse_positionals(t_arg_params *a, int i,
				  int ac, char **av)
{
  int		j;

  while (i < ac)
    {
      j = a->start;
      while (a->params[j] != NULL)
	{
	  if (my_strcmp(a->params[j]->arg, av[i]) == 0)
	    {
	      if (a->params[j]->separated)
		{
		  if (i + a->params[j]->nargs >= ac ||
		      parse_separated(a->params[j], &i, a->main, av))
		    return (STATUS_FAILURE);
		}
	      else if (parse_linked(a->params[j], a->main, av[i]))
		return (STATUS_FAILURE);
	    }
	  j++;
	}
      i++;
    }
  return (STATUS_SUCCESS);
}

int		my_parse_args(t_arg **params, int ac, char **av, void *main)
{
  int		i;
  char		**args;
  t_arg_params	a;

  if (my_args_validate(params) != STATUS_SUCCESS)
    return (STATUS_FAILURE);
  i = 0;
  a.params = params;
  a.main = main;
  while (params[i] != NULL && params[i]->required)
    {
      if (i >= ac - 1)
	return (84);
      args = my_read_nargs(i + 1, 1, av);
      if (params[i]->callback(params[i], args, main) == STATUS_FAILURE)
	return (STATUS_FAILURE);
      free(args);
      i++;
    }
  a.start = i;
  if (parse_positionals(&a, i + 1, ac, av) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
