/*
** my.h for libmy in /home/antoine.stempfer/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 15:28:15 2017 Antoine Stempfer
** Last update Mon Feb 27 20:39:54 2017 Antoine Stempfer
*/

#ifndef MY_H_
# define MY_H_

# ifndef ABS
#  define ABS(x)	((x > 0) ? (x) : (-x))
# endif /* ABS */

# ifndef MAX
#  define MAX(x, y)	((x > y) ? (x) : (y))
# endif /* MAX */

# ifndef MIN
#  define MIN(x, y)	((x > y) ? (y) : (x))
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

typedef struct		s_list
{
  void			*value;
  struct s_list		*next;
}			t_list;

typedef enum
  {
    B_FALSE,
    B_TRUE
  }			t_bool;


typedef struct		s_arg
{
  char			*identifier;
  t_bool		required;
  char			*shorthand;
  char			*description;
  int			nargs;
  int			(*callback)(struct s_arg *, t_list *, void *);
}			t_arg;

typedef struct		s_arg_parser
{
  t_list		*required;
  t_list		*optional;
  char			*description;
  char			*help_id;
  void			*main;
}			t_arg_parser;

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

void			my_list_append(t_list **, void *);

void			my_list_prepend(t_list **, void *);

void			my_list_insert(t_list **, void *, int);

int			my_list_len(t_list *);

void			*my_list_delete(t_list **, int);

void			my_list_remove(t_list **, void *);

t_list			*my_list_from_strtab(char **);

void			my_list_destroy(t_list **);

void			my_list_free(t_list **);

void			my_list_nfree(t_list **, int);

void			*my_list_find(t_list *, void *,
				      int (*)(void *, void *));

void			*my_list_get(t_list *, int);

void			my_list_sort(t_list **, int (*)(void *, void *), int);

void			my_list_rotate(t_list **);

t_list			*my_list_clone(t_list *);

t_list			*my_list_sublist(t_list *, int, int);

void			*my_list_next(t_list *);

t_arg_parser		*my_argparse_create(void *, char *, char *);

int			my_argparse_show_help(char *, t_arg_parser *);

t_arg			*my_argparse_add_required(t_arg_parser *, char *,
						  int (*)(t_arg *,
							  t_list *,
							  void *));


t_arg			*my_argparse_add_optional(t_arg_parser *, char *,
						  int,
						  int (*)(t_arg *,
							  t_list *,
							  void *));

t_arg			*my_argparse_add_optional_shorthand(t_arg_parser *,
							    char *,
							    int,
							    int (*)(t_arg *,
								    t_list *,
								    void *));

int			my_argparse_parse(t_arg_parser *, int, char **, void *);

#endif /* MY_H_ */
