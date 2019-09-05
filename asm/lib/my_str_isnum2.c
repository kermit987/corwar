/*
** my_str_isnum2.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 30 14:20:35 2015 lionel karmes
** Last update Mon Mar 30 14:28:41 2015 lionel karmes
*/

#include "my.h"

int	my_str_isnum2(char *str, int i, int j)
{
  if (my_strlen(str) <= i)
    return (0);
  if (str[i] == '-')
    i++;
  while (str[i] != '\0' && i < j)
    {
      if (*(str + i) < 48 || *(str + i) > 57)
	return (0);
      i = i + 1;
    }
  return (1);
}
