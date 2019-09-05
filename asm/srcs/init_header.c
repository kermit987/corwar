/*
** init_header.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 17:09:56 2015 lionel karmes
** Last update Fri Apr 10 15:29:08 2015 Steven Loo Fat
*/

#include "my.h"

int	load_name(char *name, char *str, int i, int name_or_comment)
{
  int	len;
  int	size;

  len = 0;
  if (name_or_comment == PROG_NAME)
    size = PROG_NAME_LENGTH;
  else
    size = COMMENT_LENGTH;
  if ((multiple_inclusion(name, name_or_comment)) == -1)
    return (-1);
  while (str[i + len] != '\0' && str[i + len] != '\"')
    len++;
  if (str[i + len] == '\"')
    {
      if (len > size)
	{
	  msg_warning_header_overflow(name_or_comment);
	  len = size;
	}
      name = my_strncpy(name, &str[i], len);
      return (0);
    }
  return (invalid_name_or_comment(name_or_comment));
}

void	raz_header(header_t *header)
{
  int	i;

  header->magic = COREWAR_EXEC_MAGIC;
  i = 1;
  header->prog_name[0] = -1;
  while (i < PROG_NAME_LENGTH + 1)
    header->prog_name[i++] = 0;
  header->prog_size = 0;
  i = 1;
  header->comment[0] = -1;
  while (i < COMMENT_LENGTH + 1)
    header->comment[i++] = 0;
}

int	next(header_t *header, char *buff)
{
  if (!(my_strncmp(".name \"", buff, 7)))
    {
      if ((load_name(&header->prog_name[0], buff, 7, PROG_NAME)) == -1)
	return (-1);
    }
  else if (!(my_strncmp(".comment \"", buff, 10)))
    {
      if (header->prog_name[0] == -1)
	{
	  free(buff);
	  return (msg_error_header_name());
	}
      if ((load_name(&header->comment[0], buff, 10, COMMENT)) == -1)
	return (-1);
      free(buff);
      return (0);
    }
  else
    {
      free(buff);
      return (msg_error_header(header));
    }
  return (1);
}

int		init_header(header_t *header, int fd_read, int *line)
{
  char		*buff;
  int		valid;

  raz_header(header);
  while ((buff = get_next_line(fd_read)))
    {
      (*line)++;
      if (!(buff = epur_str(buff)))
      	return (-1);
      if (buff[0] != '\0')
	{
	  valid = next(header, buff);
	  if (valid == -1)
	    return (-1);
	  else if (valid == 0)
	    break;
	}
      free(buff);
    }
  return (msg_error_header(header));
}
