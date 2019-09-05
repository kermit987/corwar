##
## Makefile for  in /home/karmes_l/test/tmp_Piscine_C_J11/lib/my
## 
## Made by lionel karmes
## Login   <karmes_l@epitech.net>
## 
## Started on  Mon Oct 20 10:29:02 2014 lionel karmes
## Last update Fri Jun 19 13:47:14 2015 Steven Loo Fat
##

CC	= cc

RM	= rm -f

CFLAGS += -Wextra -Wall -Werror
CFLAGS += -ansi -pedantic
CFLAGS += -I./include/

LDFLAGS =

SRCS	= count_num.c \
	  convert_base.c \
	  my_charisalpha.c \
	  my_charisnum.c \
	  my_getnbr.c \
	  my_fputchar.c \
	  my_putchar.c \
	  my_putcharerror.c \
	  my_putnbr.c \
	  my_putstr.c \
	  my_putstrerror.c \
	  my_revstr.c \
	  my_show_wordtab.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strcpy3.c \
	  my_strdup.c \
	  my_strdup2.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isnum2.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_str_to_wordtab.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strncpy2.c \
	  my_strnum_to_wordtab.c \
	  my_strstr.c \
	  my_charstr.c \
	  my_strstr2.c \
	  my_strupcase.c \
	  my_swap.c \
	  pmalloc.c \
	  pow_10.c \
	  power.c \
	  replace_by_argument.c \
	  remove_comment.c \
	  epur_str.c \
	  my_strtablen.c \
	  delete_n_caractere.c \
	  get_next_line.c

NAME	= libmy.a

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) $(LDFLAGS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re
