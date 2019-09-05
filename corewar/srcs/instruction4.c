/*
** instruction4.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/save/The real corewar/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sat Apr 11 12:53:52 2015 lionel karmes
** Last update Sun Apr 12 22:38:04 2015 huy le
*/

#include "instruction.h"

int		xor(t_champ *champion, char map[MAP_SIZE],
		    t_process *proc, unsigned int cycle)
{
  int		nb_octet;
  int		i;
  int		tab[3];

  nb_octet = 0;
  proc->cd = op_tab[7].nbr_cycles;
  if (op_tab[7].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(8, map[proc->pc]) == 0)
    return (1);
  i = 0;
  while (i < op_tab[7].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc]);
      champion->type = argc_define_octal(7, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i++] = get_nb2(champion, map, proc->pc + nb_octet, proc);
      if (champion->type == 0)
	return (1);
    }
  champion->regs[tab[2]] = tab[0] ^ tab[1];
  if (champion->regs[tab[2]] == 0)
    champion->carry = 1;
  return (nb_octet);
}

int	lfork(t_champ *champion, char map[MAP_SIZE],
	      t_process *proc, unsigned int cycle)
{
  proc->cd = op_tab[14].nbr_cycles;
  if (op_tab[11].nbr_cycles > (int)cycle
      || find_type(0, map[proc->pc + 1] != T_DIR))
    return (1);
  if (!(champion->proc = realloc(champion->proc,
				 sizeof(t_process) * (champion->proc_nbr + 1))))
    {
      my_fprintf(ERROUT, REALLOC, champion->id, champion->header.prog_name);
      champion->id = 0;
    }
  champion->proc_nbr += 1;
  champion->proc[champion->proc_nbr].pc = proc->pc
    + (get_nb(map, proc->pc + 1, 2));
  champion->proc[champion->proc_nbr].cd = 0;
  return (1);
}
