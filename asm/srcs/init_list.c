/*
** init_list.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/save/coreware_asm/corewar_copy/CPE_2014_corewar/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Apr 10 16:22:04 2015 lionel karmes
** Last update Sat Apr 11 17:37:04 2015 lionel karmes
*/

#include "my.h"

int		init_lists(t_lists *lists)
{
  t_list	*list_label;
  t_list	*list_op_code;

  if (!(list_label = new_list()))
    return (-1);
  list_label->what_element = LABEL;
  lists->list_label = list_label;
  if (!(list_op_code = new_list()))
    return (-1);
  list_op_code->what_element = OP_CODE;
  lists->list_op_code = list_op_code;
  return (0);
}

int	remove_lists(t_lists *lists)
{
  remove_list(&lists->list_label);
  remove_list(&lists->list_op_code);
  return (-1);
}
