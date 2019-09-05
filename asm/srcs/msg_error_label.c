/*
** msg_error_label.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Mar 26 13:55:33 2015 lionel karmes
** Last update Fri Apr 10 10:48:04 2015 Steven Loo Fat
*/

#include "my.h"

int	msg_error_label(char *str)
{
  my_putstr("[ERROR] : label invalid : ");
  my_putstr(str);
  my_putstr("\nLABEL_CHARS = \"");
  my_putstr(LABEL_CHARS);
  my_putstr("\"\n");
  free(str);
  return (-1);
}

int	msg_error_label_unknown(char *str)
{
  my_putstr("[ERROR] : label ");
  my_putstr(str);
  my_putstr(" doesn't exist\n");
  free(str);
  return (0);
}

int	msg_error_label_multiple(char *str)
{
  my_putstr("[ERROR] : label already exist : ");
  my_putstr(str);
  my_putchar('\n');
  free(str);
  return (-1);
}
