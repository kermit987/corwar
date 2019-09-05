/*
** champion.h for corewar in /home/metz_a/brouillons/corewar/include
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 12:23:50 2015 Aurélien Metz
** Last update Sun Apr 12 21:44:31 2015 huy le
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# include "op.h"

typedef struct	s_header
{
  char		prog_name[PROG_NAME_LENGTH + 1];
  char		comment[COMMENT_LENGTH + 5];
  unsigned int	prog_size;
}		t_header;

typedef struct	s_processor
{
  unsigned int	pc;
  unsigned int	cd;
}		t_process;

typedef struct	s_champ
{
  unsigned char	id;
  t_header	header;
  unsigned int	proc_nbr;
  t_process	*proc;
  unsigned int	addr;
  int		regs[REG_NUMBER];
  char		alive;
  char		carry;
  args_type_t	type;
}		t_champ;

#endif /* !CHAMPION_H_ */
