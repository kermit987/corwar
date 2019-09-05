/*
** get_next_line.c for line in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:09:24 2015 huy le
** Last update Sun Apr 12 22:09:52 2015 huy le
*/

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void		line0(char *line, unsigned int size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
    line[i++] = 0;
}

char	*my_realloc(int size, char *old)
{
  char	*new;

  if (!(new = fmalloc(sizeof(char) * (my_strlen(old) + size + 1))))
    {
      free(old);
      return (NULL);
    }
  my_strcpy(new, old);
  free(old);
  return (new);
}

int		put_read_in_line(char **line, char *buff)
{
  static int	cpt;
  static short	save = 0;
  int		i;

  if (!save)
    cpt = 0;
  i = my_strlen(line[0]);
  save = 0;
  while (buff[cpt])
    {
      if (i && !(i % BUFFER_SIZE))
	if (!(line[0] = my_realloc(sizeof(char) * (BUFFER_SIZE + 1), line[0])))
	  return (0);
      if (buff[cpt] == '\n')
	{
	  cpt++;
	  save = 1;
	  line[0][i] = 0;
	  return (2);
	}
      line[0][i++] = buff[cpt++];
    }
  line[0][i] = 0;
  return (1);
}

char		*get_next_line(const int fd)
{
  char		*line;
  int		ret;
  static char	buff[BUFFER_SIZE + 1];
  static short	status = 0;

  if (!(line = fmalloc(sizeof(char) * (BUFFER_SIZE + 1))))
    return (NULL);
  line0(line, (BUFFER_SIZE + 1));
  while (1)
    {
      if (!status || status == 1)
	{
	  if (!(ret = read(fd, buff, BUFFER_SIZE)))
	    {
	      free(line);
	      return (NULL);
	    }
	  buff[ret] = '\0';
	}
      if (!(status = put_read_in_line(&line, buff)))
	return (NULL);
      if (status == 2)
	return (line);
    }
}
