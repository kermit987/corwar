##
## Makefile<2> for my select in /home/metz_a/rendu/System unix/PSU_2014_my_select
## 
## Made by Aurélien Metz
## Login   <metz_a@epitech.net>
## 
## Started on  Thu Jan  8 17:26:59 2015 Aurélien Metz
## Last update Thu Apr  9 15:15:46 2015 Aurélien Metz
##

##########################################
NAME	=	../libmy.a
OBJS	=	$(SRCS:.c=.o)
IFLAGS	=	-I ../include
CFLAGS	+=	-Wall -Wextra -Werror -g3
CFLAGS	+=	-ansi -pedantic $(IFLAGS)
AR	=	ar rc
RANLIB	=	ranlib
RM	=	rm -f
##########################################
SRCS	=	call_fct_specified.c \
		display_it2.c \
		display_it.c \
		fmalloc.c \
		my_putnbr.c \
		my_atoi.c \
		my_atoi_base.c \
		my_char_is_num.c \
		my_fprintf.c \
		my_printnbr.c \
		my_putchar.c \
		my_puterror.c \
		my_putstr.c \
		my_strcpy.c \
		my_strlen.c \
		my_strcmp.c \
		my_strdup.c \
		my_str_to_wordtab.c \
		get_next_line.c \
		xread.c \
		str_in_format.c \
##########################################
all:		$(NAME)

$(NAME):	$(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RANLIB) $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

.c.o:
		@printf "\033[36m[gcc]\033[37m  $<\n"
		@gcc $(CFLAGS) $(IFLAGS) -c $< -o $@
		@printf "\033[0m"

re:		fclean all

.PHONY:		all clean fclean re
##########################################
