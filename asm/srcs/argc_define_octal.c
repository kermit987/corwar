/*
** argc_define_octal.c for  in /home/loofat_s/rendu/coreware_asm/asm/lib
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Tue Mar 31 15:31:16 2015 Steven Loo Fat
** Last update Fri Apr 10 10:27:55 2015 Steven Loo Fat
*/

#include "my.h"

int	argc_define_octal(char code, int type, int position)
{
  if (type == T_REG)
    return (1);
  else if (type == T_IND)
    return (IND_SIZE);
  else if (code == op_tab[0].code)
    return (4);
  else if (code == op_tab[8].code)
    return (2);
  else if (code == op_tab[9].code || code == op_tab[13].code)
    {
      if (position == 0 || position == 1)
	return (2);
    }
  else if (code == op_tab[10].code)
    {
      if (position == 1 || position == 2)
	return (2);
    }
  else if (code == op_tab[11].code || code == op_tab[14].code)
    return (2);
  return (DIR_SIZE);
}
