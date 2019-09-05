/*
** split_argument.c for  in /home/loofat_s/rendu/coreware_asm/asm/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Fri Apr  3 16:47:32 2015 Steven Loo Fat
** Last update Sat Apr 11 19:49:21 2015 huy le
*/

#include "my.h"

int	remove_tag_buff_part_2(char **str, char **str2,
				     char **tag, int i)
{
  if (tag != NULL)
    if (!(*tag = my_strdup2(*str, 0, i)))
      return (-1);
  if ((*str)[i + 1] == ' ')
    i++;
  if (!((*str2) = my_strdup2(*str, i + 1, my_strlen(*str))))
    {
      if (tag != NULL)
	free(*tag);
      return (-1);
    }
  return (0);
}

int	remove_tag_buff(char **str, char **tag)
{
  char	*str2;
  int	i;

  i = 0;
  while ((*str)[i] != '\0' && (*str)[i] != LABEL_CHAR && (*str)[i] != ' ')
    i++;
  if ((*str)[i] != LABEL_CHAR)
    {
      if (tag != NULL)
	*tag = NULL;
      return (0);
    }
  if ((remove_tag_buff_part_2(str, &str2, tag, i)) == -1)
    {
      free(*str);
      return (-1);
    }
  free(*str);
  *str = str2;
  return (0);
}

int	split_argument_next(char **final_argument, t_list *list,
			    t_op_code *op_code, int fd_write)
{
  int	i;

  i = 0;
  while (final_argument[i] != NULL)
    {
      final_argument[i] = epur_str(final_argument[i]);
      if ((write_fd(final_argument[i], list, op_code, fd_write)) == -1)
	{
	  free_tab(final_argument);
	  return (-1);
	}
      i++;
    }
  free_tab(final_argument);
  return (0);
}

int	split_argument(char **str, t_list *list,
		       t_op_code *op_code, int fd_write)
{
  int	i;
  char	**final_argument;

  i = 0;
  if (remove_tag_buff(str, NULL) == -1)
    return (-1);
  while ((*str)[i] != ' ' && (*str)[i] != '\0')
    i++;
  if (i == my_strlen(*str))
    return (1);
  final_argument = my_str_to_wordtab(&(*str)[i], ',');
  write_type(fd_write, op_code->o_code, 1);
  if (define_octal_value(op_code->o_code) == 2)
    write_type(fd_write, op_code->o_param, 1);
  return (split_argument_next(final_argument, list, op_code, fd_write));
}
