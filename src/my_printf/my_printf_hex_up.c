/*
** my_printf_hex_up.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:54:12 2017 Antoine Stempfer
** Last update Fri Mar 24 09:56:23 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_hex_up(va_list args, int unused __attribute__((unused)))
{
  return (my_unumstr_base(va_arg(args, unsigned int), BASE_HEX_UP));
}
