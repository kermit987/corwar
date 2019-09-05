/*
** remove_element.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell2/v1/minishell2
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Feb 26 20:12:07 2015 lionel karmes
** Last update Fri Apr 10 10:53:32 2015 Steven Loo Fat
*/

#include "my.h"

void		remove_list_label(t_label *tmp)
{
  t_label      	*element;

  while (tmp != NULL)
    {
      element = tmp;
      if (tmp->name != NULL)
	free(tmp->name);
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_op_code(t_op_code *tmp)
{
  t_op_code    	*element;

  while (tmp != NULL)
    {
      element = tmp;
      tmp = tmp->e_next;
      free(element);
    }
}
