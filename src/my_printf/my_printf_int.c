/*
** my_printf_int.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:45:31 2017 Antoine Stempfer
** Last update Fri Mar 24 10:37:47 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_int(va_list args, int unused __attribute__((unused)))
{
  return (my_numstr(va_arg(args, int)));
}
