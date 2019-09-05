/*
** define_octal_value.c for  in /home/loofat_s/rendu/coreware_asm/asm/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Tue Mar 31 14:42:24 2015 Steven Loo Fat
** Last update Fri Apr 10 10:18:43 2015 Steven Loo Fat
*/

#include "my.h"
#include "op.h"

int	define_octal_value(char code)
{
  if (code == op_tab[0].code)
    return (1);
  else if (code == op_tab[8].code)
    return (1);
  else if (code == op_tab[11].code)
    return (1);
  else if (code == op_tab[14].code)
    return (1);
  return (2);
}
