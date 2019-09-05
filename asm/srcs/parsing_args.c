/*
** parsing_arg.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sun Mar 29 13:43:56 2015 lionel karmes
** Last update Fri Apr 10 10:52:32 2015 Steven Loo Fat
*/

#include "my.h"

int		valid_args(char *str)
{
  int		(*ptr[3])(char *);
  int		i;
  int		valid;

  ptr[0] = &valid_args_dir;
  ptr[1] = &valid_args_ind;
  ptr[2] = &valid_args_reg;
  i = 0;
  while (i < 3)
    {
      valid = ptr[i](str);
      if (valid == -1)
	return (-1);
      if (valid > 0)
	return (valid);
      i++;
    }
  my_putstr("[ERROR] : args type invalid : T_UNKNOWN\n");
  return (-1);
}

args_type_t	what_args_type(char *str)
{
  if (my_strlen(str) == 0)
    {
      my_putstr("[ERROR] : invalid len args\n");
      return (-1);
    }
  return (valid_args(str));
}

int		check_args(char **args, char code, t_list **list_op_code)
{
  int		i;
  args_type_t	type;
  int		size_octet;
  t_op_code	*op_code;

  i = 0;
  size_octet = define_octal_value(code);
  if (init_op_code(&op_code, code) == -1)
    return (-1);
  while (args[i] != NULL)
    {
      supp_space(args[i], 0, ' ', ':');
      if ((type = what_args_type(args[i])) == -1)
      	return (-1);
      if ((op_tab[code - 1].type[i] & type) != type)
      	return (msg_error_args_type(type));
      size_octet += argc_define_octal(code, type, i);
      update_op_code(op_code, i, type);
      i++;
    }
  put_end_element_op_code(list_op_code, op_code);
  return (size_octet);
}

int		parsing_args(int *pc, char code, char *str, t_list **list_op_code)
{
  char		**args;
  int		ac;
  int		size_octet;

  if (!(args = my_str_to_wordtab(str, SEPARATOR_CHAR)))
    return (-1);
  free(str);
  ac = my_strtablen(args);
  if (ac != op_tab[code - 1].nbr_args)
    {
      free_tab(args);
      return (msg_error_args(code));
    }
  if ((size_octet = check_args(args, code, list_op_code)) == -1)
    {
      free_tab(args);
      return (-1);
    }
  free_tab(args);
  (*pc) += size_octet;
  return (1);
}
