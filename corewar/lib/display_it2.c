/*
** display_it2.c for print in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:07:31 2015 huy le
** Last update Sun Apr 12 22:07:58 2015 huy le
*/

#include "my_fprintf.h"

int		my_printadr(const int fd, va_list arg_list)
{
  unsigned long	adress;
  short		ret;

  ret = 0;
  adress = va_arg(arg_list, unsigned long);
  if (adress == 0)
    return (my_fputstr(fd, "(nill)"));
  ret += my_fputstr(fd, "0x");
  return (my_fputnbr_base(fd, adress, "0123456789abcdef") + ret);
}

int		my_fputnbr_base(const int fd, unsigned long nb, char *base)
{
  unsigned long	divisor;
  unsigned int	base_len;
  short		ret;

  base_len = my_strlen(base);
  divisor = 1;
  ret = 0;
  while ((nb / divisor) >= base_len)
    divisor = divisor * base_len;
  while (divisor > 0)
    {
      ret += my_fputchar(fd, base[(nb / divisor) % base_len]);
      divisor = divisor / base_len;
    }
  return (ret);
}

int		my_printStr(const int fd, va_list arg_list)
{
  char		*str;
  short		ret;
  unsigned int	i;

  i = 0;
  ret = 0;
  str = va_arg(arg_list, char *);
  while (str[i])
    {
      if (str[i] <= 32 || str[i] >= 127)
	{
	  ret += my_fputchar(fd, '\\');
	  ret += my_fputnbr_base(fd, (int)str[i], "01234567");
	}
      else
	ret += my_fputchar(fd, str[i]);
      i = i + 1;
    }
  return (ret);
}

int		my_printnbr_b(const int fd, va_list arg_list)
{
  unsigned int nb;

  nb = va_arg(arg_list, unsigned int);
  return (my_fputnbr_base(fd, nb, "01"));
}

int	my_printchar(const int fd, va_list arg_list)
{
  char	c;

  c = va_arg(arg_list, int);
  return (my_fputchar(fd, c));
}
