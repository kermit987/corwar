/*
** put_element.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell2/v1/minishell2
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Feb 26 19:55:46 2015 lionel karmes
** Last update Tue Apr 14 10:01:22 2015 Steven Loo Fat
*/

#include "my.h"

void		put_end_element_label(t_list **list, t_label *element)
{
  t_label	*label_l_end;

  label_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      label_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_label(t_list **list, t_label *element)
{
  t_label      	*label_l_start;

  label_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      label_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}

void		put_end_element_op_code(t_list **list, t_op_code *element)
{
  t_op_code	*op_code_l_end;

  op_code_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      op_code_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_op_code(t_list **list, t_op_code *element)
{
  t_op_code    	*op_code_l_start;

  op_code_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      op_code_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}
