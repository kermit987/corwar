/*
** game.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 19:13:27 2015 Aurélien Metz
** Last update Sun Apr 12 16:47:19 2015 Aurélien Metz
*/

#include "game.h"

void		game(t_champ champions[NBR_CHAMP],
		     char map[MAP_SIZE], int dump)
{
  unsigned int	cycle_to_die;
  unsigned int	cycle;

  cycle_to_die = CYCLE_TO_DIE;
  if (dump == 0)
    dump--;
  while (alive(champions) > 1 && dump)
    {
      cycle = 0;
      while (cycle < CYCLE_TO_DIE)
	{
	  do_cycle(champions, map, cycle_to_die - cycle);
	  cycle++;
	  dump--;
	}
      dead(champions);
    }
  winner(champions);
}

void			do_cycle(t_champ champions[NBR_CHAMP],
				 char map[MAP_SIZE], unsigned int cycle)
{
  static t_champ	*order[NBR_CHAMP + 1];
  static char		first_use = 1;
  unsigned int		cpt;
  int			i;

  if (first_use)
    {
      first_use = 0;
      get_order(champions, order);
    }
  i = 0;
  while (order[i])
    {
      cpt = 0;
      while (cpt < order[i]->proc_nbr)
	{
	  order[i]->proc[cpt].cd -= order[i]->proc[cpt].cd ? 1 : 0;
	  if (!order[i]->proc[cpt].cd)
	    if (execute(order[i], cpt, map, cycle))
	      order[i]->proc[cpt].pc +=
		live(champions, (order[i]->proc) + cpt, map, cycle);
	  cpt++;
	}
      i++;
    }
}

void	dead(t_champ champions[NBR_CHAMP])
{
  int	i;

  i = 0;
  while (champions[i].id && i < NBR_CHAMP)
    {
      if (champions[i].alive == 0)
	{
	  free(champions[i].proc);
	  champions[i].id = 0;
	}
      champions[i].alive = 0;
      i++;
    }
}

int	nbr_champ(t_champ champions[NBR_CHAMP], int id)
{
  int	i;

  i = 0;
  while (champions[i].id && i < NBR_CHAMP && champions[i].id != id)
    i++;
  if (champions[i].id == id)
    return (i);
  return (0);
}

void	get_order(t_champ champions[NBR_CHAMP], t_champ *order[NBR_CHAMP + 1])
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (champions[i].id && i < NBR_CHAMP)
    {
      if ((order[j] = champions + nbr_champ(champions, i + 1)))
	j++;
      i++;
    }
}
