/*
** load_champions.c for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 17:02:55 2015 Aurélien Metz
** Last update Sun Apr 12 22:18:13 2015 huy le
*/

#include "load_champions.h"

static int	is_blp(t_blp *line, char map[MAP_SIZE])
{
  int		i;
  int		n;

  n = 0;
  i = line->pos;
  if (line->len > MAP_SIZE)
    return (0);
  while (n < line->len)
    {
      if (map[i++ % MAP_SIZE])
	return (0);
      n++;
    }
  return (1);
}

static int	check_overlap(t_champ *champion, char map[MAP_SIZE])
{
  unsigned int	i;
  int		sub_addr;

  i = 0;
  sub_addr = champion->addr;
  while (i < champion->header.prog_size)
    {
      if (map[sub_addr++ % MAP_SIZE] != 0)
	return (1);
      i++;
    }
  return (0);
}

static unsigned int	blp(char map[MAP_SIZE])
{
  t_blp			blp;
  t_blp			line;

  blp.pos = 0;
  blp.len = 1;
  line.pos = 0;
  line.len = 1;
  while ((line.pos + line.len) < MAP_SIZE)
    {
      while (is_blp(&line, map))
	line.len += 1;
      line.len -= line.len > 1 ? 1 : 0;
      if (line.len > blp.len)
	{
	  blp.pos = line.pos;
	  blp.len = line.len;
	}
      if (blp.len == MAP_SIZE)
	return (blp.pos + (blp.len / 2));
      line.pos++;
      line.len++;
    }
  return (blp.pos + (blp.len / 2));
}

int		get_loaded(t_champ *champion, int fd, char map[MAP_SIZE])
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = champion->addr;
  while (i < champion->header.prog_size)
    {
      if (xread(fd, map + j, 1) == -1)
	return (-1);
      j++;
      if (j == MAP_SIZE - 1)
	j = 0;
      i++;
    }
  close(fd);
  return (0);
}

int	load_champion(t_champ *champion, int fd, char map[MAP_SIZE])
{
  if (!champion->addr)
    champion->addr = blp(map);
  if (champion->header.prog_size > MAP_SIZE
      || check_overlap(champion, map))
    return (my_fprintf(ERROUT, OVERLAP));
  if (get_loaded(champion, fd, map)
      || !(champion->proc = fmalloc(sizeof(t_process))))
    return (-1);
  champion->proc_nbr = 1;
  champion->proc[0].pc = champion->addr;
  return (0);
}
