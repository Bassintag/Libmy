/*
** my_printf_char.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 18:04:42 2016 Antoine Stempfer
** Last update Wed Nov  9 17:02:04 2016 Antoine Stempfer
*/

#include <stdarg.h>
#include <stdlib.h>

char	*my_printf_char(va_list args)
{
  char	*result;

  result = malloc(sizeof(char) * 2);
  result[0] = (char) va_arg(args, int);
  result[1] = '\0';
  return (result);
}
