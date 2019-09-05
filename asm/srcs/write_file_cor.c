/*
** write_file_cor_header.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Apr  1 13:48:47 2015 lionel karmes
** Last update Sat Apr 11 14:25:30 2015 lionel karmes
*/

#include "my.h"

void	write_type(int fd, int nb, int nbr_octet)
{
  int	i;
  char	c;

  i = nbr_octet - 1;
  while (i >= 0)
    {
      c = nb >> (8 * i);
      my_fputchar(fd, c);
      i--;
    }
}

void	write_file_cor_header(int fd_write, header_t *header)
{
  int	i;

  write_type(fd_write, header->magic, sizeof(int));
  i = 0;
  while (i < PROG_NAME_LENGTH)
    my_fputchar(fd_write, header->prog_name[i++]);
  write(fd_write, "\000\000\000\000", 4);
  write_type(fd_write, header->prog_size, sizeof(int));
  i = 0;
  while (i < COMMENT_LENGTH)
    my_fputchar(fd_write, header->comment[i++]);
  write(fd_write, "\000\000\000\000", sizeof(int));
}

int	reposition_cursor(int fd, int line)
{
  char	*s;
  int	i;

  if (lseek(fd, 0, SEEK_SET) == (off_t) -1)
    {
      my_putstrerror("[ERROR] in reposition_cursor : lseek\n");
      return (-1);
    }
  i = 1;
  while ((s = get_next_line(fd)) && i < line)
    {
      i++;
      free(s);
    }
  if (i < line)
    {
      my_putstrerror("[ERROR] in reposition_cursor : improbable\n");
      return (-1);
    }
  return (1);
}

int		write_file_cor(int fd_read, int fd_write)
{
  header_t	header;
  t_lists	lists;
  int		line;
  int		line_after_header;

  line = 0;
  if (init_header(&header, fd_read, &line) == -1)
    return (msg_error_line(line));
  line_after_header = line;
  if (init_lists(&lists) == -1)
    return (-1);
  if (init_label(&header, &lists, fd_read, &line) == -1)
    {
      msg_error_line(line);
      return (remove_lists(&lists));
    }
  write_file_cor_header(fd_write, &header);
  if (reposition_cursor(fd_read, line_after_header) == -1)
    return (remove_lists(&lists));
  if (write_file_cor_body(fd_read, fd_write, &lists, line_after_header) == -1)
    return (remove_lists(&lists));
  remove_lists(&lists);
  return (1);
}
