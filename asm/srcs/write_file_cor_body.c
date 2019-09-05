/*
** read_file_cor.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr  2 13:22:44 2015 lionel karmes
** Last update Fri Apr 10 16:09:15 2015 lionel karmes
*/

#include "my.h"

int	what_type(char i, char o_param)
{
  char	bits;

  bits = (o_param >> (6 - i * 2)) & 3;
  return (((bits == 1) ? T_REG : ((bits == 2) ? T_DIR : T_IND)));
}

int		define_number_octal_type(char *str, t_list *list_label,
					 args_type_t *type, int pc)
{
  char		*tmp_type;
  int		i;
  int		nb;
  t_label	*label;

  i = 0;
  if (*type == T_DIR || *type == T_REG)
    i = 1;
  if (!(tmp_type = my_strdup2(str, i, my_strlen(str))))
    return (-1);
  if (my_str_islabel(tmp_type, 0, my_strlen(tmp_type)))
    {
      delete_n_caractere(tmp_type, 1);
      if (!(label = find_element_label(list_label, tmp_type)))
	{
	  *type = 0;
	  return (msg_error_label_unknown(tmp_type));
	}
      free(tmp_type);
      return (label->position - pc);
    }
  nb = my_getnbr(tmp_type);
  free(tmp_type);
  return (nb);
}

int		write_fd(char *arg, t_list *list_label,
			 t_op_code *op_code, int fd_write)
{
  static int	pc = 0;
  static char	ac = 0;
  static int	nb_octet_save = 0;
  int		nb_octet;
  int		nb;
  args_type_t	type;

  type = what_type(ac, op_code->o_param);
  nb_octet = argc_define_octal(op_code->o_code, type, ac);
  nb_octet_save += nb_octet;
  nb = define_number_octal_type(arg, list_label, &type, pc);
  if (type == 0)
    return (-1);
  write_type(fd_write, nb, nb_octet);
  ac++;
  if (ac == op_tab[op_code->o_code - 1].nbr_args)
    {
      pc += nb_octet_save + define_octal_value(op_code->o_code);
      nb_octet_save = 0;
      ac = 0;
    }
  return (1);
}

int		write_file_cor_body(int fd_read, int fd_write,
				    t_lists *lists, int line)
{
  char		*buff;
  t_op_code	*op_code;
  int		valid;

  op_code = lists->list_op_code->l_start;
  while ((buff = get_next_line(fd_read)))
    {
      line++;
      buff = epur_str(buff);
      supp_space(buff, 0, ' ', ':');
      if (buff[0] != '\0')
	{
	  valid = split_argument(&buff, lists->list_label, op_code, fd_write);
	  if (valid == -1)
	    {
	      free(buff);
	      return (msg_error_line(line));
	    }
	  if (valid == 0)
	    op_code = op_code->e_next;
	}
      free(buff);
    }
  return (0);
}
