/*
** my_printnbr.c for putnbr in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:05:12 2015 huy le
** Last update Sun Apr 12 22:06:04 2015 huy le
*/

#include "my_fprintf.h"

int		my_printnbr_o(const int fd, va_list arg_list)
{
  unsigned int	nb;

  nb = va_arg(arg_list, unsigned int);
  return (my_fputnbr_base(fd, nb, "01234567"));
}

int		my_printnbr_u(const int fd, va_list arg_list)
{
  unsigned int	nb;

  nb = va_arg(arg_list, unsigned int);
  return (my_fputnbr_base(fd, nb, "0123456789"));
}

int		my_printnbr_x(const int fd, va_list arg_list)
{
  unsigned int	nb;

  nb = va_arg(arg_list, unsigned int);
  return (my_fputnbr_base(fd, nb, "0123456789abcdef"));
}

int		my_printnbr_X(const int fd, va_list arg_list)
{
  unsigned int nb;

  nb = va_arg(arg_list, unsigned int);
  return (my_fputnbr_base(fd, nb, "0123456789ABCDEF"));
}

int     my_printnbr(const int fd, va_list arg_list)
{
  int	nb;

  nb = va_arg(arg_list, int);
  return (my_fputnbr(fd, nb));
}
