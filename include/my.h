/*
** my.h for libmy in /home/antoine.stempfer/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 15:28:15 2017 Antoine Stempfer
** Last update Wed Feb 22 16:23:13 2017 Antoine Stempfer
*/

#ifndef MY_H_
# define MY_H_

# ifndef ABS
#  define ABS(x)	((x > 0) ? (x) : (-x))
# endif /* ABS */

# ifndef MAX
#  define MAX(x,y)	((x > y) ? (x) : (y))
# endif /* MAX */

# ifndef MIN
#  define MIN(x,y)	((x > y) ? (y) : (x))
# endif /* MIN */

# ifndef BASE_HEX
#  define BASE_HEX	"0123456789abcdef"
# endif /* BASE_HEX */

# ifndef BASE_HEX_UP
#  define BASE_HEX_UP	"0123456789ABCDEF"
# endif /* BASE_HEX_UP */

# ifndef NIL_STR
#  define NIL_STR	"(nil)"
# endif /* NIL_STR */

# ifndef NULL_STR
#  define NULL_STR	"(null)"
# endif /* NULL_STR */

# ifndef STATUS_SUCCESS
#  define STATUS_SUCCESS	0
# endif /* STATUS_SUCCESS */

# ifndef STATUS_FAILURE
#  define STATUS_FAILURE	84
# endif /* STATUS_FAILURE */

typedef enum
  {
    B_FALSE,
    B_TRUE
  }			t_bool;

typedef struct		s_arg
{
  char			*arg;
  t_bool		separated;
  t_bool		required;
  int			nargs;
  int			(*callback)(struct s_arg *, char **, void *);
}			t_arg;

typedef struct		s_arg_params
{
  t_arg			**params;
  void			*main;
  int			start;
}			t_arg_params;

int			my_char_isalpha(char);

int			my_char_islower(char);

int			my_char_isnum(char);

int			my_char_isprintable(char);

int			my_char_isupper(char);

int			my_free_strtab(char **);

float			my_getfloat(char *);

int			my_getnbr_base(char *, char *);

int			my_getnbr(char *);

int			my_index_of(char, char *);

int			my_index_of_str(char *, char *);

int			my_memset(char *, char, int);

int			my_numlen(int, int);

int			my_unumlen(int, int);

int			my_ulnumlen(int, int);

char			*my_numstr(int);

int			my_power(int, int);

int			my_printf(char *, ...);

int			my_putchar(char);

int			my_putnbr_base(int, char *);

int			my_putnbr(int);

int			my_putstr(char *);

char			*my_removechar(char *, char);

int			my_readnbr(char **);

char			*my_replace(char *, char, char);

char			*my_revstr(char *);

void			my_sort_int_tab(int *, int);

void			my_sort_str_tab(char **, int);

char			**my_split(char *, char);

char			*my_strappend(char *, char *);

char			*my_strcapitalize(char *);

char			*my_strcat(char *, char *);

int			my_strcmp(char *, char *);

int			my_str_index_of(char *, char *);

char			*my_strcpy(char *, char *);

char			*my_strdup(char *);

int			my_strlen(char *);

char			*my_strlowcase(char *);

int			my_strtablen(char **);

char			*my_strupcase(char *);

char			*my_substring(char *, int, int);

void			my_swap(int *, int *);

char			*my_trim_start(char *);

int			my_parse_args(t_arg **, int, char **, void *);

int			my_args_validate(t_arg **);

#endif /* MY_H_ */
