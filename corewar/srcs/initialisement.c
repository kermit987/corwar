/*
** initialisement.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 12:41:15 2015 Aurélien Metz
** Last update Sun Apr 12 22:25:43 2015 huy le
*/

#include "initialisement.h"

int		initialisement(t_champ champions[NBR_CHAMP], char map[MAP_SIZE],
			       int ac, char **av)
{
  unsigned char	i;
  int		cpt;
  char		status;
  char		ids[NBR_CHAMP + 1];

  if (ac < MIN_ARGS || ac > MAX_ARGS)
    {
      my_fprintf(ERROUT, USAGE);
      return (-1);
    }
  cpt = 0;
  i = 0;
  my_strcpy(ids, IDS);
  if ((cpt += check_dump(av)) == -1)
    return (-1);
  while (i < NBR_CHAMP && av[cpt])
    {
      champions[i].id = 0;
      if (av[cpt])
	if ((status = init_champion(champions + i, av + cpt, ids, map)) == -1)
	  return (-1);
      cpt += status;
      i++;
    }
  return (my_atoi(av[1]));
}

int	init_champion(t_champ *champion , char **av,
		      char ids[NBR_CHAMP + 1], char map[MAP_SIZE])
{
  int	status;
  int	args;

  init_regs(champion->regs, champion->id);
  champion->alive = 0;
  champion->carry = 0;
  args = 0;
  if ((status = check_arg(champion, av + args, N, ids)) == -1)
    return (-1);
  if (!champion->id)
    champion->id = get_ids(ids, 0);
  args += status;
  if ((status = check_arg(champion, av + args, A, ids)) == -1)
    return (-1);
  args += status;
  if (!av[args] || my_strcmp(av[args] + my_strlen(av[args]) - my_strlen(COR),
			     COR))
    {
      my_fprintf(ERROUT, WRONG_COR, av[args]);
      return (-1);
    }
  if (read_file(champion, av[args], map))
    return (-1);
  return (args + 1);
}

int	check_arg(t_champ *champion, char **av,
		  char *arg, char ids[NBR_CHAMP])
{
  int	addr;

  addr = 0;
  if (!my_strcmp(av[0], arg))
    {
      if (!str_in_format(av[1], (!my_strcmp(arg, N)
				 ? FORMAT_PN : FORMAT_INT))
	  ||  (!my_strcmp(arg, N)
	       ? !(champion->id = get_ids(ids, my_atoi(av[1])))
	       : (addr = my_atoi(av[1])) < 0))
	{
	  my_fprintf(ERROUT, WRONG_PN, av[1]);
	  return (-1);
	}
      champion->addr = addr;
      return (2);
    }
  return (0);
}

int	get_ids(char ids[NBR_CHAMP], char pn)
{
  int	i;
  int	save;

  i = 0;
  while (i < NBR_CHAMP)
    {
      if (pn && ids[i] == pn)
	{
	  ids[i] = 0;
	  return (pn);
	}
      else if (!pn && ids[i])
	{
	  save = ids[i];
	  ids[i] = 0;
	  return (save);
	}
      i++;
    }
  return (0);
}

void	init_regs(int regs[NBR_REGS], int id)
{
  int	i;

  i = 0;
  while (i < NBR_REGS)
    regs[i++] = 0;
  regs[0] = id;
}
