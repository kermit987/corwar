/*
** instruction.h for corewar in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/srcs
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Fri Apr  3 17:17:21 2015 huy le
** Last update Sun Apr 12 21:40:07 2015 huy le
*/

#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

# include "champion.h"
# include <stdlib.h>

# define OCTET_LIVE	(4)
# define OCTET_AFF	(5)
# define INDX_SIZE	(6)
# define DIRX_SIZE	(8)
# define NBR_CHAMP	(4)
# define NO_WINNER	("\033[34mNo one of all players won the game.\n\033[0m")
# define INT_SIZE	(4)
# define OCTET_LD	(3)
# define MAP_SIZE	(6 * 1024)
# define REALLOC	("\033[31mThe champion: %d (%s) have been killed \
because of realloc's fail\n\033[0m")
# define WINNER		("\033[34mPlayer %d: %s (%s) won the game !\n\033[0m")
# define ERROUT		(2)
# define ALIVE		("Player %d (%s) is alive\n")
# define STDIN		(1)

/*
** prototypes
*/
int	my_fprintf(const int fd, const char *str, ...);
int	get_nb(char map[MAP_SIZE], int offset, int octet);
int	get_nb2(t_champ *champ, char map[MAP_SIZE],
		int offset, t_process *proc);
int	get_nb3(t_champ *champ, char map[MAP_SIZE],
		int offset, t_process *proc);
int	valid_reg(char map[MAP_SIZE], int offset);
char	*which_process(t_champ *champion, int prog_nbr);
int	args_valid(char code, char o_param);
int	argc_define_octal(char code, int type, int position);
int	get_type(args_type_t type);
int	find_type(char i, char o_param);
int	my_putchar(char c);

#endif /* !INSTRUCTION_H_ */
