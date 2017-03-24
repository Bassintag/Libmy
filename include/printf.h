/*
** printf.h for libmy in /home/bassintag/delivery/PSU_2021/PSU_2021_my_printf/include
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov  7 14:17:07 2016 Antoine Stempfer
** Last update Fri Mar 24 09:50:22 2017 Antoine Stempfer
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include <stdarg.h>

char	*my_printf_char(va_list, int);
char	*my_printf_str(va_list, int);
char	*my_printf_int(va_list, int);
char	*my_printf_uint(va_list, int);
char	*my_printf_bin(va_list, int);
char	*my_printf_hex(va_list, int);
char	*my_printf_hex_up(va_list, int);
char	*my_printf_oct(va_list, int);
char	*my_printf_pointer(va_list, int);
char	*my_printf_float(va_list, int);

# define ID_HASHTAG		'#'
# define ID_ZERO       		'0'
# define ID_MINUS		'-'
# define ID_SPACE		' '
# define ID_PLUS       		'+'
# define ID_LONG       		'l'

# define MODIFIER_HASHTAG	1
# define MODIFIER_ZERO		2
# define MODIFIER_MINUS		4
# define MODIFIER_SPACE		8
# define MODIFIER_PLUS		16
# define MODIFIER_LONG		32

# define MODIFIER_SPACE_PLUS	(MODIFIER_SPACE | MODIFIER_PLUS)
# define MODIFIER_ZERO_MINUS	(MODIFIER_ZERO | MODIFIER_MINUS)

# define ID_PRECISION		'.'

# define PROP_GENERIC		0
# define PROP_NUMERIC		1
# define PROP_SIGNED		2

# define PREFIX_LEN		my_strlen(type->prefix)

typedef struct	s_printf_type
{
  char		*alias;
  int		properties;
  char		*prefix;
  char		*(*func)(va_list, int);
}		t_printf_type;

typedef struct	s_printf_props
{
  int		len;
  int		prec;
  int		mods;
  t_printf_type	*type;
}		t_printf_props;

# define NUM_TYPES		10

t_printf_type	*get_format_types();
char		*my_printf_apply_modifiers(char *, t_printf_type *, int, int);

#endif
