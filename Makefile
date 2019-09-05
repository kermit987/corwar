##
## Makefile for corewar in /home/metz_a/rendu/Prog elem/CPE_2014_corewar
## 
## Made by Aurélien Metz
## Login   <metz_a@epitech.net>
## 
## Started on  Thu Mar  5 11:41:05 2015 Aurélien Metz
## Last update Tue Jun 16 12:53:28 2015 Steven Loo Fat
##

#####################################################################
all:
	@printf "\033[032m --- [ASSEMBLER] ---\033[0m\n"
	@cd asm && make -f Makefile
	@printf "\033[032m --- [VIRTUAL MACHINE] ---\033[0m\n"
	@cd corewar && make -f Makefile

clean:
	@printf "\033[031m --- [CLEAN] ---\033[0m\n"
	@cd asm && make clean -f Makefile
	@cd corewar && make clean -f Makefile

fclean:	clean
	@printf "\033[031m --- [FCLEAN] ---\033[0m\n"
	@cd asm && make fclean -f Makefile
	@cd corewar && make fclean -f Makefile

re:	fclean all

.PHONY:	all clean fclean re
#####################################################################
