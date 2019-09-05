/*
** execute.h for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Fri Apr 10 11:57:22 2015 Aurélien Metz
** Last update Fri Apr 10 15:06:12 2015 Aurélien Metz
*/

#ifndef EXECUTE_H_
# define EXECUTE_H_

# include "champion.h"
# include <stdlib.h>

# define NBR_CHAMP		(4)
# define MAP_SIZE		(6 * 1024)

/*
** prototypes
*/
void	init_ops(int (*f[NBR_OP])(t_champ *champion, char map[MAP_SIZE],
				  t_process *proc, unsigned int cycle));
int	ld(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	st(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	add(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	sub(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	and(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	or(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	xor(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	zjmp(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle);
int	ldi(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle);
int	sti(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle);
int	my_fork(t_champ *champion, char map[MAP_SIZE],
		t_process *proc, unsigned int cycle);
int	lld(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle);
int	lldi(t_champ *champion, char map[MAP_SIZE],
	     t_process *proc, unsigned int cycle);
int	lfork(t_champ *champion, char map[MAP_SIZE],
	      t_process *proc, unsigned int cycle);
int	aff(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle);

#endif /* !EXECUTE_H_ */
