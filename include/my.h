/*
** my.h for libmy in /home/antoine.stempfer/delivery/Libmy_new
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Jan 10 15:28:15 2017 Antoine Stempfer
** Last update Fri Mar 24 10:20:31 2017 Antoine Stempfer
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdarg.h>

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

typedef enum
  {
    B_FALSE,
    B_TRUE
  }			t_bool;

/*
**	MISC
*/

int			my_char_isalpha(char c);
int			my_char_islower(char c);
int			my_char_isnum(char c);
int			my_char_isprintable(char c);
int			my_char_isupper(char c);
int			my_free_strtab(char **tab);
int			my_free_tab(void **tab);
float			my_getfloat(char *str);
int			my_getnbr_base(char *str, char *base);
int			my_getnbr(char *str);
int			my_index_of(char c, char *src);
int			my_index_of_str(char *str, char *src);
void			*my_memset(void *dest, char c, size_t size);
void			*my_memcpy(void *dest, void *src, size_t size);
int			my_memcmp(void *a, void *b, size_t size);
int			my_numlen(int num, int base);
int			my_unumlen(int unum, int base);
int			my_ulnumlen(int ulnum, int base);
char			*my_numstr(int num);
int			my_power(int num, int pos);
int			my_putchar(char c);
int			my_puterr(char *err);
void			*my_puterr_null(char *err);
int			my_putnbr_base(int num, char *base);
int			my_putnbr(int num);
int			my_putstr(char *str);
char			*my_removechar(char *src, char c);
int			my_readnbr(char **str_ptr);
void			*my_realloc(void *ptr, size_t curr, size_t new);
char			*my_replace(char *src, char target, char replacement);
char			*my_revstr(char *str);
void			my_sort_int_tab(int *tab, int size);
void			my_sort_str_tab(char **str, int size);
char			**my_split(char *src, char separator);
char			*my_strappend(char *src, char *to_append);
char			*my_strappendchar(char *src, char to_append);
char			*my_strcapitalize(char *src);
char			*my_strcat(char *str1, char *str2);
int			my_strcmp(char *str1, char *str2);
int			my_strncmp(char *str1, char *str2, int length);
char			*my_strcombine(char *str1, char *str2);
int			my_strncpy(char *dest, char *src, int length);
char			*my_strcpy(char *dest, char *src);
char			*my_strdup(char *src);
int			my_strlen(char *str);
char			*my_strlowcase(char *str);
int			my_strtablen(char **tab);
char			*my_strupcase(char *str);
char			*my_substring(char *src, int start, int end);
void			my_swap(int *num1, int *num2);
char			*my_trim_start(char *src);
char			*my_unumstr(int num);
char			*my_unumstr_base(int num, char *base);

/*
**	PRINTF
*/

char			*my_vaprintf(char *str, va_list args);
char			*my_sprintf(char *str, ...);
int			my_fprintf(int fd, char *str, ...);
int			my_printf(char *str, ...);

/*
**	LISTS
*/

typedef struct		s_list
{
  void			*value;
  struct s_list		*next;
}			t_list;

void			my_list_append(t_list **list, void *new);
void			my_list_prepend(t_list **list, void *new);
void			my_list_insert(t_list **list, void *new, int index);
int			my_list_len(t_list *list);
void			*my_list_delete(t_list **list, int index);
void			my_list_remove(t_list **list, void *target);
t_list			*my_list_from_strtab(char **tab);
void			**my_list_to_tab(t_list *list);
void			my_list_destroy(t_list **list);
void			my_list_free(t_list **list);
void			my_list_nfree(t_list **list, int amount);
void			*my_list_find(t_list *list, void *target,
				      int (*cmp)(void *, void *));
void			*my_list_get(t_list *list, int index);
void			my_list_sort(t_list **list,
				     int (*cmp)(void *, void *),
				     int value_when_supp);
void			my_list_rotate(t_list **list);
t_list			*my_list_clone(t_list *list);
t_list			*my_list_sublist(t_list *list, int start, int end);
void			*my_list_next(t_list *list);

/*
**	ARGPARSE
*/

typedef struct		s_arg
{
  char			*identifier;
  t_bool		required;
  char			*shorthand;
  char			*description;
  t_list       		*argdesc;
  int			nargs;
  int			(*callback)(struct s_arg *, t_list *, void *);
}			t_arg;

typedef struct		s_arg_parser
{
  t_bool		showed_help;
  t_list		*required;
  t_list		*optional;
  char			*description;
  char			*help_id;
  void			*main;
}			t_arg_parser;

t_arg_parser		*my_argparse_create(void *, char *, char *);
void			my_argparse_destroy(t_arg_parser *);
int			my_argparse_show_usage(char *, t_arg_parser *);
int			my_argparse_show_required(t_arg_parser *);
int			my_argparse_show_options(t_arg_parser *);
int			my_argparse_show_help(char *, t_arg_parser *);
t_arg			*my_argparse_add_argdesc(t_arg *, char *);
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
