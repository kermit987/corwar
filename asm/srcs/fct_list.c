/*
** init_list.c for  in /home/karmes_l/Projets/Prog_Elem/PushSwap/v1
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Dec  9 14:41:33 2014 lionel karmes
** Last update Sat Apr 11 17:37:44 2015 lionel karmes
*/

#include "my.h"

void	my_put_in_list_end(t_list **list, void *element)
{
  if ((*list)->what_element == LABEL)
      put_end_element_label(list, (t_label *)element);
  else
    my_putstrerror("[ERROR] improbable : what_element ?1\n");
}

void	my_put_in_list_start(t_list **list, void *element)
{
  if ((*list)->what_element == LABEL)
    put_start_element_label(list, (t_label *)element);
  else
    my_putstrerror("[ERROR] improbable : what_element ?2\n");
}

t_list		*new_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->size = 0;
  list->l_start = NULL;
  list->l_end = NULL;
  return (list);
}

void	remove_list(t_list **list)
{
  if (*list != NULL)
    {
      if ((*list)->what_element == LABEL)
	remove_list_label((t_label *)(*list)->l_start);
      else if ((*list)->what_element == OP_CODE)
      	remove_list_op_code((t_op_code *) (*list)->l_start);
      else
	my_putstrerror("[ERROR improbable ; what_element ?3\n");
      free(*list);
      *list = NULL;
    }
}
