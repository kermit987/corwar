/*
** asm.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 11:56:28 2015 lionel karmes
** Last update Sat Apr 11 18:20:16 2015 huy le
*/

#include "my.h"

int	creat_file_cor(int fd_read, char *path)
{
  int	fd_write;
  char	*file_cor;
  int	len_path;

  len_path = my_strlen(path);
  if (path[len_path - 2] == '.' && path[len_path - 1] == 's')
    len_path -= 2;
  if (!(file_cor = pmalloc(sizeof(char) * len_path + my_strlen(".cor") + 1)))
    return (-1);
  my_strncpy(file_cor, path, len_path);
  my_strcat(file_cor, ".cor");
  if ((fd_write = open(file_cor, O_WRONLY | O_TRUNC | O_CREAT, 00644)) == -1)
    {
      msg_error_open(file_cor);
      free(file_cor);
      return (-1);
    }
  if (write_file_cor(fd_read, fd_write) == -1)
    return (o_trunc_error(file_cor, fd_write));
  free(file_cor);
  close(fd_write);
  return (1);
}

int	assembler(int ac, char **av)
{
  int	i;
  int	fd;

  i = 1;
  while (i < ac)
    {
      if ((fd = open(av[i], O_RDONLY)) == -1)
	return (msg_error_open(av[i]));
      if (creat_file_cor(fd, av[i]) == -1)
	{
	  close(fd);
	  my_putstr("(champion ");
	  my_putstr(av[i]);
	  my_putstr(")\n");
	  return (-1);
	}
      close(fd);
      i++;
    }
  return (1);
}
