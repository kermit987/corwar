/*
** instruction3.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Fri Apr 10 16:12:13 2015 Aurélien Metz
** Last update Sun Apr 12 22:36:49 2015 huy le
*/

#include "instruction.h"

int	my_fork(t_champ *champion, char map[MAP_SIZE],
		t_process *proc, unsigned int cycle)
{
  proc->cd = op_tab[12].nbr_cycles;
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
    + (get_nb(map, proc->pc + 1, 2) % IDX_MOD);
  champion->proc[champion->proc_nbr].cd = 0;
  return (1);
}

int	aff(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle)
{
  int	num_reg;

  proc->cd = op_tab[15].nbr_cycles;
  if (op_tab[15].nbr_cycles > (int)cycle)
    return (1);
  if (find_type(0, map[proc->pc + 1]) != T_REG)
    return (1);
  if ((num_reg = valid_reg(map, proc->pc + 1 + 1)) == 0)
    return (1);
  my_putchar(champion->regs[num_reg - 1]);
  return (OCTET_AFF);
}

int		and(t_champ *champion, char map[MAP_SIZE],
		    t_process *proc, unsigned int cycle)
{
  int		nb_octet;
  int		i;
  int		tab[3];

  nb_octet = 0;
  proc->cd = op_tab[5].nbr_cycles;
  if (op_tab[5].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(6, map[proc->pc]) == 0)
    return (1);
  i = 0;
  while (i < op_tab[5].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc]);
      champion->type = argc_define_octal(5, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i++] = get_nb2(champion, map, proc->pc + nb_octet, proc);
      if (champion->type == 0)
	return (1);
    }
  champion->regs[tab[2]] = tab[0] & tab[1];
  champion->carry = 0;
  if (champion->regs[tab[2]] == 0)
    champion->carry = 1;
  return (nb_octet);
}

int		or(t_champ *champion, char map[MAP_SIZE],
		    t_process *proc, unsigned int cycle)
{
  int		nb_octet;
  int		i;
  int		tab[3];

  nb_octet = 0;
  proc->cd = op_tab[6].nbr_cycles;
  if (op_tab[6].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(7, map[proc->pc]) == 0)
    return (1);
  i = 0;
  while (i < op_tab[6].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc]);
      champion->type = argc_define_octal(6, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i++] = get_nb2(champion, map, proc->pc + nb_octet, proc);
      if (champion->type == 0)
	return (1);
    }
  champion->regs[tab[2]] = tab[0] | tab[1];
    champion->carry = 0;
  if (champion->regs[tab[2]] == 0)
    champion->carry = 1;
  return (nb_octet);
}

short		sti(t_champ *champion, char map[MAP_SIZE],
		    t_process *proc, unsigned int cycle)
{
  int		nb_octet;
  int		i;
  int		tab[3];

  nb_octet = 0;
  proc->cd = op_tab[10].nbr_cycles;
  if (op_tab[10].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(11, map[proc->pc + 1]) == 0)
    return (1);
  i = 0;
  while (i < op_tab[10].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc]);
      champion->type = argc_define_octal(10, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i++] = get_nb2(champion, map, proc->pc + nb_octet, proc);
      if (champion->type == 0)
	return (1);
    }
  champion->carry = 0;
  if ((map[(tab[1] + tab[2]) % MEM_SIZE] = tab[0]) == 0)
    champion->carry = 1;
  return (nb_octet);
}
