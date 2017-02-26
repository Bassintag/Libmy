/*
** printf.h for libmy in /home/bassintag/delivery/PSU_2021/PSU_2021_my_printf/include
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 14:17:07 2016 Antoine Stempfer
** Last update Thu Nov 17 11:39:31 2016 Antoine Stempfer
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>

char	*my_printf_char(va_list, int, int);

char	*my_printf_str(va_list, int, int);

char	*my_printf_int(va_list, int, int);

char	*my_printf_uint(va_list, int, int);

char	*my_printf_ubin(va_list, int, int);

char	*my_printf_hex(va_list, int, int);

char	*my_printf_hex_up(va_list, int, int);

char	*my_printf_oct(va_list, int, int);

char	*my_printf_pointer(va_list, int, int);

char	*my_printf_strspe(va_list, int, int);

char	*my_printf_float(va_list, int, int);

char	*my_printf_exponent(va_list, int, int);

#define ID_HASHTAG		'#'
#define ID_ZERO			'0'
#define ID_MINUS		'-'
#define ID_SPACE		' '
#define ID_PLUS			'+'
#define ID_LONG			'l'

#define MODIFIER_HASHTAG	1
#define MODIFIER_ZERO		2
#define MODIFIER_MINUS		4
#define MODIFIER_SPACE		8
#define MODIFIER_PLUS		16
#define MODIFIER_LONG		32

#define ID_PRECISION		'.'

#define TYPE_GENERIC		0
#define TYPE_NUMERIC		1
#define TYPE_SIGNED		2

struct	s_flag
{
  char	*alias;
  char	types;
  char	*prefix;
  char	*(*func)(va_list, int, int);
};

#define NUM_FLAGS		12

struct s_flag	*get_flags();

#endif
