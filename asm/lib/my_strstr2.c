/*
** my_str_str2.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Mar 26 11:41:22 2015 lionel karmes
** Last update Thu Mar 26 13:46:28 2015 lionel karmes
*/

#include "my.h"

int	my_strstr2(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (!my_charstr(str1[i], str2))
	return (0);
      i++;
    }
  return (1);
}
