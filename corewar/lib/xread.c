/*
** xread.c for lib in /home/metz_a/rendu/System unix/PSU_2014_minishell2
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Sat Mar 14 13:20:57 2015 Aurélien Metz
** Last update Thu Apr  9 12:53:06 2015 Aurélien Metz
*/

#include "my_fprintf.h"
#include <unistd.h>

int	xread(int fd, char *buffer, int len)
{
  int	ret;

  if ((ret = read(fd, buffer, len)) <= 0)
    {
      my_fprintf(ERROUT, READ);
      return (-1);
    }
  buffer[ret] = 0;
  return (0);
}

int	uxread(int fd, unsigned char *buffer, int len)
{
  int	ret;

  if ((ret = read(fd, buffer, len)) <= 0)
    {
      my_fprintf(ERROUT, READ);
      return (-1);
    }
  buffer[ret] = 0;
  return (0);
}
