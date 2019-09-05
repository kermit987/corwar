/*
** read_files.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 15:14:14 2015 Aurélien Metz
** Last update Sun Apr 12 22:16:03 2015 huy le
*/

#include "read_files.h"

int	get_prog_size(unsigned char prog_size[INT_SIZE + 1])
{
  int	ps;
  int	i;

  ps = 0;
  i = 0;
  while (i < INT_SIZE)
    {
      ps |= prog_size[i++];
      if (i < INT_SIZE)
	ps = ps << BPO;
    }
  return (ps);
}

int		read_file(t_champ *champion, char *file, char map[MAP_SIZE])
{
  int		fd;
  char		magic[MAGIC_LENGTH + 1];
  unsigned char	prog_size[INT_SIZE + 1];

  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_fprintf(ERROUT, OPEN, file));
  if (xread(fd, magic, MAGIC_LENGTH) == -1)
    return (-1);
  if (my_strcncmp(magic, MAGIC, INT_SIZE))
    return (my_fprintf(ERROUT, ERR_MAGIC));
  if (xread(fd, champion->header.prog_name, PROG_NAME_LENGTH + 4) == -1
      || uxread(fd, prog_size, INT_SIZE))
    return (-1);
  champion->header.prog_size = get_prog_size(prog_size);
  if (xread(fd, champion->header.comment, COMMENT_LENGTH + 4) == -1)
    return (-1);
  if (load_champion(champion, fd, map))
    return (-1);
  return (0);
}
