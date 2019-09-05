/*
** execute.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Fri Apr 10 11:57:30 2015 Aurélien Metz
** Last update Sun Apr 12 22:22:07 2015 huy le
*/

#include "execute.h"

int	execute(t_champ *champion, int proc,
		char map[MAP_SIZE], unsigned int cycle)
{
  int	(*f[NBR_OP])(t_champ *champion, char map[MAP_SIZE],
		     t_process *proc, unsigned int cycle);
  char	found;
  int	i;

  i = 1;
  if (map[champion->proc[proc].pc] == 1)
    return (1);
  init_ops(f);
  found = 0;
  while (i < NBR_OP)
    if (map[champion->proc[proc].pc] == op_tab[i++].code)
      {
	champion->proc[proc].pc
	  += f[i - 2](champion, map, champion->proc + proc, cycle);
	found = 1;
      }
  if (!found)
    {
      champion->proc[proc].cd = 1;
      champion->proc[proc].pc += 1;
    }
  champion->proc[proc].pc %= MAP_SIZE;
  return (0);
}

void	init_ops(int (*f[NBR_OP])(t_champ *champion, char map[MAP_SIZE],
				  t_process *proc, unsigned int cycle))
{
  f[0] = &ld;
  f[1] = &st;
  f[2] = &add;
  f[3] = &sub;
  f[4] = &and;
  f[5] = &or;
  f[6] = &xor;
  f[7] = &zjmp;
  f[8] = &ldi;
  f[9] = &sti;
  f[10] = &my_fork;
  f[11] = &lld;
  f[12] = &lldi;
  f[13] = &lfork;
  f[14] = &aff;
  f[15] = NULL;
}
