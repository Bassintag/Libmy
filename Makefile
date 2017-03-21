##
## Makefile for libmy.a in /home/antoine.stempfer/delivery/Libmy_new
##
## Made by Antoine Stempfer
## Login   <antoine.stempfer@epitech.eu>
##
## Started on  Tue Jan 10 15:31:33 2017 Antoine Stempfer
## Last update Tue Mar 21 15:29:40 2017 Antoine Stempfer
##

CC	=	gcc -O2

AR	=	ar rc

RM	=	rm -f

CFLAGS	=	-Wextra -Wall -I $(INC)

INC	=	include

NAME	=	libmy.a

OBJS	=	$(SRCS:.c=.o)

SRCS	=	src/my_char_isalpha.c \
		src/my_char_islower.c \
		src/my_char_isnum.c \
		src/my_char_isprintable.c \
		src/my_char_isupper.c \
		src/my_free_tab.c \
		src/my_free_strtab.c \
		src/my_getfloat.c \
		src/my_getnbr_base.c \
		src/my_getnbr.c \
		src/my_index_of.c \
		src/my_memset.c \
		src/my_numlen.c \
		src/my_numstr.c \
		src/my_power.c \
		src/my_putchar.c \
		src/my_puterr.c \
		src/my_putnbr_base.c \
		src/my_putnbr.c \
		src/my_putstr.c \
		src/my_readnbr.c \
		src/my_removechar.c \
		src/my_replace.c \
		src/my_revstr.c \
		src/my_sort_int_tab.c \
		src/my_sort_str_tab.c \
		src/my_split.c \
		src/my_strappend.c \
		src/my_strappendchar.c \
		src/my_strcapitalize.c \
		src/my_strcat.c \
		src/my_strcmp.c \
		src/my_strncmp.c \
		src/my_strncpy.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_strlowcase.c \
		src/my_strtablen.c \
		src/my_strupcase.c \
		src/my_substring.c \
		src/my_swap.c \
		src/my_trim.c \
		src/my_printf/my_printf.c \
		src/my_printf/my_printf_char.c \
		src/my_printf/my_printf_exponent.c \
		src/my_printf/my_printf_flags.c \
		src/my_printf/my_printf_float.c \
		src/my_printf/my_printf_hex.c \
		src/my_printf/my_printf_int.c \
		src/my_printf/my_printf_oct.c \
		src/my_printf/my_printf_pointer.c \
		src/my_printf/my_printf_str.c \
		src/my_printf/my_printf_strspe.c \
		src/my_printf/my_printf_ubin.c \
		src/my_printf/my_printf_uint.c \
		src/my_argparse/my_argparse_add_required.c \
		src/my_argparse/my_argparse_add_optional.c \
		src/my_argparse/my_argparse_add_argdesc.c \
		src/my_argparse/my_argparse_create.c \
		src/my_argparse/my_argparse_destroy.c \
		src/my_argparse/my_argparse_parse.c \
		src/my_argparse/my_argparse_parse_required.c \
		src/my_argparse/my_argparse_parse_optional.c \
		src/my_argparse/my_argparse_show_usage.c \
		src/my_argparse/my_argparse_show_required.c \
		src/my_argparse/my_argparse_show_options.c \
		src/my_argparse/my_argparse_show_help.c \
		src/my_lists/my_list_append.c \
		src/my_lists/my_list_destroy.c \
		src/my_lists/my_list_delete.c \
		src/my_lists/my_list_remove.c \
		src/my_lists/my_list_nfree.c \
		src/my_lists/my_list_free.c \
		src/my_lists/my_list_find.c \
		src/my_lists/my_list_get.c \
		src/my_lists/my_list_insert.c \
		src/my_lists/my_list_len.c \
		src/my_lists/my_list_prepend.c \
		src/my_lists/my_list_sort.c \
		src/my_lists/my_list_update.c \
		src/my_lists/my_list_rotate.c \
		src/my_lists/my_list_clone.c \
		src/my_lists/my_list_sublist.c \
		src/my_lists/my_list_from_strtab.c \
		src/my_lists/my_list_to_tab.c \
		src/my_lists/my_list_next.c


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
