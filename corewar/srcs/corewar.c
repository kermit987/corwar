/*
** corewar.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 12:37:49 2015 Aurélien Metz
** Last update Sun Apr 12 10:58:08 2015 Aurélien Metz
*/

#include "corewar.h"

int		main(int ac, char **av)
{
  t_champ	champions[NBR_CHAMP];
  char		map[MAP_SIZE];
  int		dump;

  all_zero(champions);
  if ((dump = initialisement(champions, map, ac, av + 1)) == -1)
    return (-1);
  game(champions, map, dump);
  return (0);
}

void		all_zero(t_champ champions[NBR_CHAMP])
{
  unsigned char	i;

  i = 0;
  while (i < NBR_CHAMP)
    champions[i++].id = 0;
}
