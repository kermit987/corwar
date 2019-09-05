/*
** valid_args.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 30 17:34:45 2015 lionel karmes
** Last update Sat Apr 11 20:03:34 2015 lionel karmes
*/

#include "my.h"

int	my_str_islabel(char *str, int i, int j)
{
  int	i_save;

  if (my_strlen(str) <= i)
    return (0);
  if (str[i] != ':')
    return (0);
  i++;
  i_save = i;
  while (str[i] && i < j)
    {
      if (!my_charstr(str[i], LABEL_CHARS))
	return (0);
      i++;
    }
  if (i_save == i)
    return (0);
  return (1);
}

int	valid_args_dir(char *str)
{
  char	*tmp;

  if (str[0] != '%')
    return (0);
  if (!(tmp = my_strdup2(str, 1 , my_strlen(str))))
    return (-1);
  if (my_str_isnum2(tmp, 0, my_strlen(tmp)))
    {
      if (ABS(my_getnbr(tmp)) > IDX_MOD)
	msg_warning_args_size(str, T_DIR);
      free(tmp);
      return (T_DIR);
    }
  if (my_str_islabel(tmp, 0, my_strlen(tmp)))
    {
      free(tmp);
      return (T_DIR);
    }
  free(tmp);
  return (msg_error_args_dir(str));
}

int    	valid_args_ind(char *str)
{
  if (str[0] == '-')
    str = &str[1];
  if (my_charisnum(str[0]) && my_str_isnum(str))
    {
      if (ABS(my_getnbr(str)) > IDX_MOD)
	return (msg_warning_args_size(str, T_IND));
      return (T_IND);
    }
  if (my_str_islabel(str, 0, my_strlen(str)))
    return (T_IND);
  return (0);
}

int	valid_args_reg(char *str)
{
  if (str[0] != 'r')
    return (0);
  if (my_strlen(str) == 1)
    return (msg_error_args_reg(str));
  if (my_strlen(str) > 1 && (str[1] <= '0' || str[1] > '9'))
    return (msg_error_args_reg(str));
  if (my_strlen(str) > 2 && (str[2] < '0' || str[2] > '6'))
    return (msg_error_args_reg(str));
  if (my_strlen(str) > 3)
    return (msg_error_args_reg(str));
  return (T_REG);
}
