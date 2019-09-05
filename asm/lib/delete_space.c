/*
** delete_space.c for  in /home/loofat_s/rendu/corewar_copy/CPE_2014_corewar/asm/lib
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Fri Apr 10 10:17:21 2015 Steven Loo Fat
** Last update Sat Apr 11 18:51:55 2015 huy le
*/

#include "my.h"

int	until_word(char *str, char delimiter)
{
  int	i;

  i = 0;
  while (str[i] == delimiter)
    i++;
  return (i);
}

char	*delete_at_the_end(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  if (i > 0)
    i--;
  while (str[i] == ' ')
    {
      str[i]  = '\0';
      i--;
    }
  return (str);
}

char	*delete_at_the_begin(char *str)
{
  int	size;
  char	*new;
  int	start_of_the_word;

  size = 0;
  start_of_the_word = until_word(str, ' ');
  while (str[start_of_the_word] != '\0')
    {
      start_of_the_word++;
      size++;
    }
  start_of_the_word = until_word(str, ' ');
  if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
    {
      my_putstr("Error: malloc inside deleted_at_the_begin function failed\n");
      return (NULL);
    }
  new = my_strncpy(new, &str[start_of_the_word], size);
  free(str);
  return (new);
}
