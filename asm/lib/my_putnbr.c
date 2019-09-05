/*
** my_put_nbr.c for my_put_nbr in /home/karmes_l/test/tmp_Piscine_C_J03
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  1 16:28:28 2014 lionel karmes
** Last update Sat Apr 11 18:47:55 2015 huy le
*/

#include "my.h"

void	my_putnbr(long nb)
{
  int	total_char;
  int	i;
  int	c_all;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  total_char = count_num(nb);
  i = total_char;
  while (i > 0)
    {
      c_all = (int)(nb / pow_10(i - 1));
      my_putchar(48 + c_all);
      nb = nb - c_all * pow_10(i - 1);
      i = i - 1;
    }
}
