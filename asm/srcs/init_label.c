/*
** init_label.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Mar 25 15:43:41 2015 lionel karmes
** Last update Sat Apr 11 19:56:03 2015 huy le
*/

#include "my.h"

int		valid_label(t_list **list_label, char *tmp, int *pc)
{
  t_label	*label;

  if (my_strstr2(tmp, LABEL_CHARS))
    {
      if (find_element_label(*list_label, tmp) != NULL)
	return (msg_error_label_multiple(tmp));
      if (!(label = pmalloc(sizeof(t_label))))
	{
	  free(tmp);
	  return (-1);
	}
      label->position = *pc;
      label->name = tmp;
      my_put_in_list_end(list_label, label);
      return (1);
    }
  return (msg_error_label(tmp));
}

int		handle_data_label(t_list **list_label, char **str, int *pc)
{
  char		*tag;

  if (remove_tag_buff(str, &tag) == -1)
    return (-1);
  if (tag == NULL)
    return (0);
  return (valid_label(list_label, tag, pc));
}

int	init_label(header_t *header, t_lists *lists,
		   int fd_read, int *line)
{
  char	*buff;
  int	pc;
  int	label;

  pc = 0;
  while ((buff = get_next_line(fd_read)))
    {
      (*line)++;
      buff = epur_str(buff);
      if (buff[0] != '\0')
	{
	  supp_space(buff, 0, ' ', ':');
	  label = handle_data_label(&lists->list_label, &buff, &pc);
	  if (label == -1 ||
	      (buff[0] != '\0' &&
	       split_instruction(buff, &pc, &lists->list_op_code) == -1))
	    {
	      free(buff);
	      return (-1);
	    }
	}
      free(buff);
    }
  header->prog_size = pc;
  return (1);
}
