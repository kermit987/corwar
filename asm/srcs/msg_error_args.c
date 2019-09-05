/*
** msg_error_arg.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 30 17:29:54 2015 lionel karmes
** Last update Thu Apr  2 13:09:48 2015 lionel karmes
*/

#include "my.h"

int	msg_error_args_dir(char *str)
{
  my_putstr("[ERROR] : invalid arg direct : ");
  my_putstr(str);
  my_putchar('\n');
  return (-1);
}

int	msg_error_args_reg(char *str)
{
  my_putstr("[ERROR] : invalid arg registre : ");
  my_putstr(str);
  my_putchar('\n');
  return (-1);
}

int	msg_error_args(char code)
{
  my_putstr("[ERROR] : args invalid : ");
  my_putstr(op_tab[code - 1].mnemonique);
  my_putstr(", take ");
  my_putnbr(op_tab[code - 1].nbr_args);
  my_putstr(" args");
  my_putchar('\n');
  return (-1);
}

int	msg_error_args_type(args_type_t type)
{
  my_putstr("[ERROR] : args type invalid : ");
  if (type == T_REG)
    my_putstr("T_REG");
  else if (type == T_DIR)
    my_putstr("T_DIR");
  else if (type == T_IND)
    my_putstr("T_IND");
  else
    my_putstr("T_UNKNOWN");
  my_putchar('\n');
  return (-1);
}
