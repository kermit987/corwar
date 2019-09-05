/*
** init_op_code.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Apr  3 14:49:21 2015 lionel karmes
** Last update Fri Apr 10 10:41:14 2015 Steven Loo Fat
*/

#include "my.h"

int	init_op_code(t_op_code **op_code, char code)
{
  if (!(*op_code = pmalloc(sizeof(t_op_code))))
    return (-1);
  (*op_code)->o_code = code;
  (*op_code)->o_param = 0;
  return (0);
}

void	update_op_code(t_op_code *op_code, int i, args_type_t type)
{
  char	bits;

  bits = ((type == T_REG) ? 1 : ((type == T_DIR) ? 2 : 3));
  op_code->o_param |= bits << (6 - i * 2);
}
