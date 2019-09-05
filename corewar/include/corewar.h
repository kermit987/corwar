/*
** corewar.h for corewar in /home/metz_a/rendu/Prog elem/CPE_2014_corewar/vm
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Mon Mar 23 12:30:35 2015 Aurélien Metz
** Last update Sun Apr 12 21:41:38 2015 huy le
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "champion.h"
# include <stdlib.h>

# define NBR_CHAMP		(4)
# define MAP_SIZE		(6 * 1024)

/*
** prototypes
*/
int	initialisement(t_champ champions[NBR_CHAMP], char map[MAP_SIZE],
		       int ac, char **av);
void	game(t_champ champions[NBR_CHAMP], char map[MAP_SIZE], int dump);
void	all_zero(t_champ champions[NBR_CHAMP]);

#endif /* !COREWAR_H_ */
