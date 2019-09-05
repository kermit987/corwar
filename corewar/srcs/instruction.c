/*
** instruction.c for instruction in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/srcs
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Fri Apr  3 17:08:28 2015 huy le
** Last update Sun Apr 12 22:54:42 2015 huy le
*/

#include "instruction.h"

int	find_type(char i, char o_param)
{
  char	bits;

  bits = (o_param >> (6 - i * 2)) & 3;
  return (((bits == 1) ? T_REG : ((bits == 2) ? T_DIR : T_IND)));
}

int	live(t_champ champions[NBR_CHAMP], t_process *proc,
	     char map[MAP_SIZE], unsigned int cycle)
{
  int	prog_nbr;
  int	i;

  proc->cd = op_tab[0].nbr_cycles;
  if (op_tab[0].nbr_cycles > (int)cycle)
    return (1);
  prog_nbr = get_nb(map, proc->pc + 1, INT_SIZE);
  i = 0;
  while (i < NBR_CHAMP && champions[i].id)
    {
      if (champions[i].id == prog_nbr)
	{
	  champions[i].alive = 1;
	  my_fprintf(STDIN, ALIVE, prog_nbr, champions[i].header.prog_name);
	}
      i++;
    }
  return (OCTET_LIVE + 1);
}

int	ld(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle)
{
  int	regld1;
  int	regld2;

  proc->cd = op_tab[1].nbr_cycles;
  if (op_tab[1].nbr_cycles > (int)cycle)
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
       get_nb(map, (proc->pc + (regld1 % IDX_MOD)) % MAP_SIZE, 4)) == 0)
    champion->carry = 1;
  return (1 + IND_SIZE + 2);
}

int	st(t_champ *champion, char map[MAP_SIZE],
	   t_process *proc, unsigned int cycle)
{
  int	regst1;
  int	regst2;

  proc->cd = op_tab[2].nbr_cycles;
  if (op_tab[2].nbr_cycles > (int)cycle)
    return (1);
  if (find_type(0, map[proc->pc + 1]) != T_REG
      || find_type(1, map[proc->pc + 1]) == T_DIR)
    return (1);
  if ((regst1 = valid_reg(map, proc->pc + 1)) == 0)
    return (1);
  if (find_type(1, map[proc->pc + 1]) == T_REG)
    {
      if ((regst2 = valid_reg(map, proc->pc + 1 + 1)) == 0)
	return (1);
      champion->regs[regst2 - 1] = champion->regs[regst1 - 1];
      return (1 + 1 + 2);
    }
  regst2 = get_nb(map, proc->pc + 1 + 1, 2);
  champion->regs[regst1 - 1] =
   get_nb(map, (proc->pc + (regst2 % IDX_MOD)) % MAP_SIZE, 4);
  return (1 + 2 + 2);
}

int	add(t_champ *champion, char map[MAP_SIZE],
	    t_process *proc, unsigned int cycle)
{
  int	regadd1;
  int	regadd2;
  int	regadd3;

  proc->cd = op_tab[3].nbr_cycles;
  if (op_tab[3].nbr_cycles > (int)cycle)
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
	champion->regs[regadd1 - 1] + champion->regs[regadd2 - 1];
      champion->carry = 0;
      if (champion->regs[regadd3 - 1] == 0)
	champion->carry = 1;
      return (1 + 1 + 1 + 2);
    }
  return (1);
}
