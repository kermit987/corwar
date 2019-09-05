/*
** utils_instruction.c for instruction in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/srcs
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Thu Apr  9 16:53:44 2015 huy le
** Last update Sun Apr 12 12:45:02 2015 Aurélien Metz
*/

#include "instruction.h"

int		get_type(args_type_t type)
{
  if (type == INDX_SIZE || type == DIRX_SIZE)
    return (2);
  return (type);
}

int		args_valid(char code, char o_param)
{
  args_type_t	type;
  int		i;

  i = 0;
  while (i < op_tab[code - 1].nbr_args)
    {
      type = find_type(i, o_param);
      if ((op_tab[code - 1].type[i] & type) != type)
	return (0);
      ++i;
    }
  return (1);
}

int	get_nb(char map[MAP_SIZE], int offset, int octet)
{
  int   i;
  int	nb;

  i = 0;
  nb = 0;
  while (i < octet)
    {
      nb |= map[offset + i];
      if (i != octet - 1)
	nb = nb << 8;
      i++;
    }
  return (nb);
}

int	valid_reg(char map[MAP_SIZE], int offset)
{
  int	num_reg;

  num_reg = get_nb(map, offset, 1);
  if (num_reg <= 0 || num_reg > 16)
    return (0);
  return (num_reg);
}

void	winner(t_champ champions[NBR_CHAMP])
{
  int	i;
  char	alive;
  int	winner;

  i = 0;
  alive = 0;
  while (i < NBR_CHAMP)
    if (champions[i++].id)
      {
	alive++;
	winner = i - 1;
      }
  if (alive == 0 || alive > 1)
    my_fprintf(STDIN, NO_WINNER);
  else
    my_fprintf(STDIN, WINNER, champions[winner].id,
	       champions[winner].header.prog_name,
	       champions[winner].header.comment);
}
