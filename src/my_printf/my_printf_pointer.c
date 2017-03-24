/*
** my_printf_pointer.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Mar 24 09:55:30 2017 Antoine Stempfer
** Last update Fri Mar 24 09:55:36 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_pointer(va_list args, int unused __attribute__((unused)))
{
  void	*ptr;

  ptr = va_arg(args, void *);
  if (ptr == NULL)
    return (my_strdup(NIL_STR));
  return (my_unumstr_base((unsigned long) ptr, BASE_HEX));
}
