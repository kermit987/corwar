/*
** my_putnbr.c for putnbr in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:11:30 2015 huy le
** Last update Sun Apr 12 22:11:31 2015 huy le
*/

#include "utils.h"

int	my_putnbr(int nb)
{
  int	ret;

  ret = 0;
  if (nb == -2147483648)
    return (my_putstr("-2147483648"));
  if (nb < 0)
    {
      nb = -nb;
      ret += my_putchar('-');
    }
  if (nb >= 10)
    return (my_putnbr(nb / 10) + ret);
  return (my_putchar((nb % 10) + '0'));
}

int	my_fputnbr(const int fd, int nb)
{
  int	ret;

  ret = 0;
  if (nb == -2147483648)
    return (my_fputstr(fd, "-2147483648"));
  if (nb < 0)
    {
      nb = -nb;
      ret += my_fputchar('-', fd);
    }
  if (nb >= 10)
    return (my_fputnbr(nb / 10, fd) + ret);
  return (my_fputchar(fd, (nb % 10) + '0'));
}
