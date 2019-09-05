/*
** get_next_line1.c for get_nextline in /home/le_n/rendu/PSU_2014_minishell1
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Fri Jan 30 12:48:24 2015 huy le
** Last update Sat Apr 11 17:25:33 2015 lionel karmes
*/

#include "get_next_line.h"
#include "my.h"

int	is_there_enter(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	return (1);
      i = i + 1;
    }
  return (0);
}

char		*my_realloc(char *to_alloc, int size)
{
  char		*new_mal;
  static int	i;

  if (size == 0)
    return (to_alloc);
  if (to_alloc == NULL)
    return (NULL);
  if ((new_mal = malloc(sizeof(char) * (my_strlen(to_alloc) + size + 1 + i)))
      == NULL)
    {
      write(2, "malloc failed\n", 14);
      exit(1);
    }
  my_strcpy(new_mal, to_alloc);
  i = i + 2;
  free(to_alloc);
  return (new_mal);
}

int	early(char **buffer, int *ret, const int fd)
{
  if ((*buffer = malloc(2)) == NULL)
    return (2);
  (*buffer)[0] = 0;
  (*buffer)[1] = 0;
  if ((*ret = read(fd, *buffer, 1)) != 1)
    {
      if ((*ret == 0) && ((*buffer)[0]))
	return (1);
      else
	{
	  free(*buffer);
	  return (2);
	}
    }
  if ((*buffer)[0] == '\0')
    return (1);
  (*buffer)[*ret] = '\0';
  if ((*buffer)[0] == '\n')
    {
      (*buffer)[0] = 0;
      return (1);
    }
  return (0);
}

int	read_loop(char **buffer, int *i, int *ret, const int fd)
{
  *buffer = my_realloc(*buffer, 1);
  if (*i == 0)
    *i = *i + 1;
  if ((*ret = read(fd, *buffer + *i, 1)) != 1)
    {
      if (*ret == 0)
	return (1);
      else
	{
	  free(*buffer);
	  return (2);
	}
    }
  (*buffer)[*i + 1] = '\0';
  *i = *i + 1;
  return (0);
}

char	*get_next_line(const int fd)
{
  char	*buffer;
  int	ret;
  int	i;
  int	ret_func;

  if ((ret_func = early(&buffer, &ret, fd)) == 1)
    return (buffer);
  else if (ret_func == 2)
    return (NULL);
  i = 0;
  while (is_there_enter(buffer) == 0)
    {
      if ((ret_func = read_loop(&buffer, &i, &ret, fd)) == 1)
	return (buffer);
      else if (ret_func == 1)
	return (NULL);
    }
  buffer[i - 1] = '\0';
  return (buffer);
}
