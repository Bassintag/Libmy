/*
** my_printf_bin.c for libmy in /home/antoine.stempfer/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Mar 23 23:49:49 2017 Antoine Stempfer
** Last update Thu Mar 23 23:52:01 2017 Antoine Stempfer
*/

#include "my.h"
#include "printf.h"

char	*my_printf_bin(va_list args, int unused __attribute__((unused)))
{
  return (my_unumstr_base(va_arg(args, int), "01"));
}
