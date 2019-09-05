/*
** utils2.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Fri Apr 10 15:37:55 2015 Aurélien Metz
** Last update Sun Apr 12 22:37:23 2015 huy le
*/

#include "instruction.h"
#include "initialisement.h"

int	check_dump(char **av)
{
  if (!my_strcmp(av[0], DUMP))
    {
      if (!str_in_format(av[1], FORMAT_INT))
	{
	  my_fprintf(ERROUT, INV_DUMP, av[1]);
	  return (-1);
	}
      return (2);
    }
  return (0);
}

int		get_nb2(t_champ *champ, char map[MAP_SIZE],
			int offset, t_process *proc)
{
  int		num;

  if (champ->type == 1)
    {
      if ((num = valid_reg(map, offset)) == 0)
	champ->type = 0;
      else
	return (champ->regs[num]);
    }
  if (champ->type == DIR_SIZE)
    return (get_nb(map, offset, DIR_SIZE));
  if (champ->type == DIRX_SIZE)
    return (get_nb(map, offset, 2));
  else
    {
      num = (proc->pc + (get_nb(map, offset, IND_SIZE) % IDX_MOD)) % MEM_SIZE;
      return (get_nb(map, map[num], (champ->type == IND_SIZE) ? REG_SIZE : 2));
    }
  return (0);
}

int	get_nb3(t_champ *champ, char map[MAP_SIZE],
		int offset, t_process *proc)
{
  int	num;

  if (champ->type == 1)
    {
      if ((num = valid_reg(map, offset)) == 0)
	champ->type = 0;
      else
	return (champ->regs[num]);
    }
  if (champ->type == DIR_SIZE)
    return (get_nb(map, offset, DIR_SIZE));
  if (champ->type == DIRX_SIZE)
    return (get_nb(map, offset, 2));
  else
    {
      num = (proc->pc + (get_nb(map, offset, IND_SIZE))) % MAP_SIZE;
      return (get_nb(map, map[num], (champ->type == IND_SIZE) ? REG_SIZE : 2));
    }
  return (0);
}

int	dirx_or_indx(args_type_t type)
{
  if (type == DIR_SIZE)
    return (DIRX_SIZE);
  else
    return (INDX_SIZE);
}

int	argc_define_octal(char code, int type, int position)
{
  if (type == T_REG)
    return (1);
  else if (code == op_tab[0].code)
    return (4);
  else if (code == op_tab[8].code)
    return (dirx_or_indx(type));
  else if (code == op_tab[9].code || code == op_tab[13].code)
    {
      if (position == 0 || position == 1)
	return (dirx_or_indx(type));
    }
  else if (code == op_tab[10].code)
    {
      if (position == 1 || position == 2)
	return (dirx_or_indx(type));
    }
  else if (code == op_tab[11].code || code == op_tab[14].code)
    return (dirx_or_indx(type));
  else if (type == T_IND)
    return (IND_SIZE);
  return (DIR_SIZE);
}
