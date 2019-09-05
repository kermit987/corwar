/*
** my_putcharerror.c for  in /home/karmes_l/Projets/Systeme_Unix/my_select/v4/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Jan  9 16:02:59 2015 lionel karmes
** Last update Sat Apr 11 17:32:46 2015 lionel karmes
*/

#include "my.h"

void	my_putcharerror(char c)
{
  (void)write(2, &c, 1);
}
