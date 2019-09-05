/*
** instruction2.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Fri Apr 10 16:11:06 2015 Aurélien Metz
** Last update Sun Apr 12 22:20:29 2015 huy le
*/

#include "instruction.h"

int	sub(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle)
{
  int	regadd1;
  int	regadd2;
  int	regadd3;

  proc->cd = op_tab[4].nbr_cycles;
  if (op_tab[4].nbr_cycles > (int)cycle)
    return (1);
  if ((find_type(0, map[proc->pc + 1]) == T_REG)
      && (find_type(1, map[proc->pc + 1]) == T_REG)
      && (find_type(2, map[proc->pc + 1]) == T_REG))
    {
      regadd1 = valid_reg(map, proc->pc + 1);
      regadd2 = valid_reg(map, proc->pc + 1 + 1);
      regadd3 = valid_reg(map, proc->pc + 1 + 2);
      if (!regadd1 || !regadd2 || !regadd3)
	return (1);
      champion->regs[regadd3 - 1] =
	champion->regs[regadd1 - 1] - champion->regs[regadd2 - 1];
      champion->carry = 0;
      if (champion->regs[regadd3 - 1] == 0)
	champion->carry = 1;
      return (1 + 1 + 1 + 2);
    }
  return (1);
}

int	zjmp(t_champ *champion, char map[MAP_SIZE],
	     t_process *proc, unsigned int cycle)
{
  int	jmp;

  proc->cd = op_tab[8].nbr_cycles;
  if (op_tab[8].nbr_cycles > (int)cycle)
    return (1);
  jmp = get_nb(map, proc->pc + 1, 2);
  if (champion->carry != 1)
    return (2 + 1);
  proc->pc = (proc->pc + (jmp % IDX_MOD)) % MAP_SIZE;
  return (0);
}

int		ldi(t_champ *champion, char map[MAP_SIZE],
		    t_process *proc, unsigned int cycle)
{
  int		i;
  int		nb_octet;
  int		tab[3];

  proc->cd = op_tab[9].nbr_cycles;
  if (op_tab[9].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(10, map[proc->pc + 1]) == 0)
    return (1);
  i = 0;
  while (i < op_tab[9].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc + 1]);
      champion->type = argc_define_octal(10, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i++] = get_nb2(champion, map, proc->pc + 1 + nb_octet, proc);
      if (champion->type == 0)
	return (1);
    }
  champion->carry = 0;
  if ((champion->regs[tab[2]] =
    get_nb(map, (proc->pc + ((tab[0] + tab[1]) % IDX_MOD)) % MAP_SIZE,
	   REG_SIZE)) == 0)
    champion->carry = 1;
  return (nb_octet + 2);
}

int	lld(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle)
{
  int	regld1;
  int	regld2;

  proc->cd = op_tab[12].nbr_cycles;
  if (op_tab[12].nbr_cycles > (int)cycle)
    return (1);
  if (find_type(1, map[proc->pc + 1]) != T_REG
      || find_type(0, map[proc->pc + 1]) == T_REG)
    return (1);
  if (find_type(0, map[proc->pc + 1]) == T_DIR)
    {
      regld1 = get_nb(map, proc->pc + 1, 4);
      if ((regld2 = valid_reg(map, proc->pc + 1 + 4)) == 0)
	return (1);
      champion->regs[regld2 - 1] = regld1;
      return (1 + DIR_SIZE + 2);
    }
  regld1 = get_nb(map, proc->pc + 1, 2);
  if ((regld2 = valid_reg(map, proc->pc + 1 + 2)) == 0)
    return (1);
    champion->carry = 0;
  if ((champion->regs[regld2 - 1] =
       get_nb(map, (proc->pc + regld1) % MAP_SIZE, 4)) == 0)
    champion->carry = 1;
  return (1 + IND_SIZE + 2);
}

int		lldi(t_champ *champion, char map[MAP_SIZE],
		     t_process *proc, unsigned int cycle)
{
  int		i;
  int		nb_octet;
  int		tab[3];

  proc->cd = op_tab[13].nbr_cycles;
  if (op_tab[13].nbr_cycles > (int)cycle)
    return (1);
  if (args_valid(14, map[proc->pc + 1]) == 0)
    return (1);
  while (i < op_tab[13].nbr_args)
    {
      champion->type = find_type(i, map[proc->pc + 1]);
      champion->type = argc_define_octal(10, champion->type, i);
      nb_octet += get_type(champion->type);
      tab[i] = get_nb3(champion, map, proc->pc + 1 + nb_octet, proc);
      if (champion->type == 0)
	return (1);
      ++i;
    }
  champion->carry = 0;
  if ((champion->regs[tab[2] - 1] =
       get_nb(map, (proc->pc + (tab[0] + tab[1])) % MAP_SIZE, REG_SIZE)) == 0)
    champion->carry = 1;
  return (nb_octet);
}
