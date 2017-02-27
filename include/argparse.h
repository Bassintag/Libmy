/*
** argparse.h for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Feb 26 17:50:24 2017 Antoine Stempfer
** Last update Mon Feb 27 14:49:02 2017 Antoine Stempfer
*/

#ifndef ARGPARSE_H_
# define ARGPARSE_H_

# include "my.h"

int	my_argparse_parse_required(t_list **, t_list **, void *);

int	my_argparse_parse_optional(t_arg_parser *, t_list **, void *);

#endif /* ARGPARSE_H_ */
