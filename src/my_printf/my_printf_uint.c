/*
** my_printf_uint.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:46:35 2017 Antoine Stempfer
** Last update Fri Mar 24 10:01:34 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_uint(va_list args, int unused __attribute__((unused)))
{
  return (my_unumstr(va_arg(args, unsigned int)));
}
