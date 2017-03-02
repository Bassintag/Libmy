/*
** my_puterr.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar  2 20:19:59 2017 Antoine Stempfer
** Last update Thu Mar  2 20:23:31 2017 Antoine Stempfer
*/

#include <unistd.h>
#include "my.h"

int	my_puterr(char *err)
{
  int	len;

  len = my_strlen(err);
  write(2, err, len * sizeof(char));
  return (STATUS_FAILURE);
}
