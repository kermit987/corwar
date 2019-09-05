/*
** replace_by_argument.c for  in /home/loofat_s/rendu/CPE_2014_corewar/asm/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Mon Mar 23 17:47:49 2015 Steven Loo Fat
** Last update Fri Apr 10 10:19:35 2015 Steven Loo Fat
*/

#include "my.h"

char	*replace_by_argument(char *str, char current_av, char new_av)
{
  int	i;

  i = 0;
  if (str == NULL || current_av == 0 || new_av == 0)
    {
      my_putstr("Error replace_by_argument_function failed\n");
      return (NULL);
    }
  while (str[i] != '\0')
    {
      if (str[i] == current_av)
	str[i] = new_av;
      i++;
    }
  return (str);
}
