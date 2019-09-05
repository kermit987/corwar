/*
** gmae.h for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 19:13:44 2015 Aurélien Metz
** Last update Sun Apr 12 21:41:55 2015 huy le
*/

#ifndef GAME_H_
# define GAME_H_

# include "champion.h"
# include <stdlib.h>

# define NBR_CHAMP		(4)
# define MAP_SIZE		(6 * 1024)

/*
** prototypes
*/
void	do_cycle(t_champ championds[NBR_CHAMP], char map[MAP_SIZE],
		 unsigned int cycle);
void	get_order(t_champ champions[NBR_CHAMP], t_champ *order[NBR_CHAMP + 1]);
void	dead(t_champ champions[NBR_CHAMP]);
int	execute(t_champ *champion, int proc,
		char map[MAP_SIZE], unsigned int cycle);
int	live(t_champ champions[NBR_CHAMP], t_process *proc, char *map,
	     unsigned int cycle);
void	winner(t_champ champions[NBR_CHAMP]);
int	alive(t_champ champions[NBR_CHAMP]);

#endif /* !GAME_H_ */
