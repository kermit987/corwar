/*
** fct_element.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Mar 31 16:33:23 2015 lionel karmes
** Last update Tue Mar 31 16:40:03 2015 lionel karmes
*/

#include "my.h"

t_label		*find_element_label(t_list *list, char *name)
{
  int		i;
  t_label	*tmp;

  i = 0;
  tmp = list->l_start;
  while (i < list->size)
    {
      if (!my_strcmp(name, tmp->name))
	return (tmp);
      tmp = tmp->e_next;
      i++;
    }
  return (NULL);
}
