/*
** my_argparse_add_argdesc.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Mar  1 16:39:54 2017 Antoine Stempfer
** Last update Wed Mar  1 16:42:26 2017 Antoine Stempfer
*/

#include "my.h"

t_arg	*my_argparse_add_argdesc(t_arg *arg, char *desc)
{
  my_list_append(&arg->argdesc, desc);
  return (arg);
}
