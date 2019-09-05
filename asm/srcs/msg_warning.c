/*
** msg_warning.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Mar 31 21:19:20 2015 lionel karmes
** Last update Wed Apr  8 13:10:28 2015 Steven Loo Fat
*/

#include "my.h"

void	msg_warning_header_overflow(int name_or_comment)
{
  my_putstr("[WARNING] : lenght of ");
  if (name_or_comment == PROG_NAME)
    {
      my_putstr("name is too big, it will be truncted\nPROG_NAME_LENGHT = ");
      my_putnbr(PROG_NAME_LENGTH);
    }
  else
    {
      my_putstr("comment is too big it will be truncted\nCOMMENT_LENGHT = ");
      my_putnbr(PROG_NAME_LENGTH);
    }
  my_putchar('\n');
}

int	msg_warning_args_size(char *str, int flag)
{
  my_putstr("[WARNING] : invalid arg ");
  if (flag == T_DIR)
    my_putstr("direct size : ");
  else
    my_putstr("indirect size : ");
  my_putstr(str);
  my_putchar('\n');
  return (1);
}
