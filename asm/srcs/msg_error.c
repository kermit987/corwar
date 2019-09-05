/*
** msg_error.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 12:38:57 2015 lionel karmes
** Last update Fri Apr 10 15:49:08 2015 lionel karmes
*/

#include "my.h"

int	msg_error_open(char *path)
{
  my_putstrerror("[ERROR] : openfile : ");
  my_putstrerror(path);
  my_putcharerror('\n');
  return (-1);
}

int	o_trunc_error(char *path, int fd)
{
  int	fd2;

  close(fd);
  if ((fd2 = open(path, O_WRONLY | O_TRUNC)) == -1)
    {
      free(path);
      return (msg_error_open(path));
    }
  close(fd2);
  free(path);
  return (-1);
}

int	msg_error_line(int line)
{
  my_putstr("(error, line ");
  my_putnbr(line);
  my_putstr(")\n");
  return (-1);
}
