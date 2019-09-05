/*
** my_putchar.c for  in /home/karmes_l/test/my_function
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  8 09:38:56 2014 lionel karmes
** Last update Sat Apr 11 17:31:28 2015 lionel karmes
*/

#include "my.h"

void	my_putchar(char c)
{
  (void)write(1, &c, 1);
}
