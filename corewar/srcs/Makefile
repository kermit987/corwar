##
## Makefile for corewar in /home/metz_a/rendu/Prog elem/CPE_2014_corewar/vm
## 
## Made by Aurélien Metz
## Login   <metz_a@epitech.net>
## 
## Started on  Mon Mar 23 12:06:05 2015 Aurélien Metz
## Last update Sun Apr 12 22:39:54 2015 huy le
##

#####################################################
CC	=	gcc $(CFLAGS)
RM	=	rm -f
NAME	=	../corewar
CFLAGS	=	-Werror -Wextra -Wall 
CFLAGS	+=	-ansi -pedantic -I ../include
LDFLAGS	=	-lmy -L ..
OBJ	=	$(SRC:.c=.o)
#####################################################
SRC	=	op.c \
		corewar.c \
		initialisement.c \
		read_files.c \
		load_champions.c \
		game.c \
		execute.c \
		instruction.c \
		instruction2.c \
		instruction3.c \
		instruction4.c \
		utils.c \
		utils2.c \
		utils3.c \
#####################################################
all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

.c.o:
		@printf "\033[36m[gcc]\033[37m  $<\n"
		@$(CC) $(LDFLAGS) -c $< -o $@
		@printf "\033[0m"

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
#####################################################
