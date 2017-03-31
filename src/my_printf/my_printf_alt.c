/*
** my_printf_alt.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:31:48 2017 Antoine Stempfer
** Last update Thu Mar 30 12:25:23 2017 Antoine Stempfer
*/

#include <unistd.h>
#include "my.h"

char		*my_sprintf(char *str, ...)
{
  va_list	args;

  va_start(args, str);
  return (my_vaprintf(str, args));
}

int		my_printf(char *str, ...)
{
  va_list	args;
  char		*res;

  va_start(args, str);
  if ((res = my_vaprintf(str, args)) == NULL)
    return (STATUS_FAILURE);
  my_putstr(res);
  free(res);
  return (STATUS_SUCCESS);
}

int		my_fprintf(int fd, char *str, ...)
{
  va_list	args;
  char		*res;

  va_start(args, str);
  if ((res = my_vaprintf(str, args)) == NULL)
    return (STATUS_FAILURE);
  if (write(fd, res, my_strlen(res)) == -1)
    {
      free(res);
      return (STATUS_FAILURE);
    }
  free(res);
  return (STATUS_SUCCESS);
}
