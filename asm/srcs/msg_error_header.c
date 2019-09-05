/*
** msg_error_header.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Mar 24 13:25:40 2015 lionel karmes
** Last update Sat Apr 11 17:37:57 2015 lionel karmes
*/

#include "my.h"

int	msg_error_header(header_t *header)
{
  if (header->prog_name[0] < 0)
    {
      my_putstr("[ERROR] : manque du '.name \"\"'\n");
      return (-1);
    }
  if (header->prog_name[0] == 0)
    {
      my_putstr("[ERROR] : manque de texte entre les '\"' du '.name \"\"'\n");
      return (-1);
    }
  if (header->comment[0] == -1)
    {
      my_putstr("[ERROR]: manque du '.commment \"\"' avant\n");
      return (-1);
    }
  return (1);
}

int	msg_error_header_name()
{
  my_putstr("[ERROR] : il n'y a pas de '.name \"\"' avant");
  my_putstr(" le '.comment \"\"'\n");
  return (-1);
}

int	multiple_inclusion(char *name, int name_or_comment)
{
  if (name[0] != -1 && name_or_comment == PROG_NAME)
    {
      my_putstr("Error: multiple inclusion of .name\n");
      return (-1);
    }
  if (name[0] != -1 && name_or_comment == PROG_NAME)
    {
      my_putstr("Error: multiple inclusion of .comment\n");
      return (-1);
    }
  return (0);
}

int	invalid_name_or_comment(int name_or_comment)
{
  if (name_or_comment == PROG_NAME)
    my_putstr("Error: invalid name\n");
  else
    my_putstr("Error: invalid comment\n");
  return (-1);
}
