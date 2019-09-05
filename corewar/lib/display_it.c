/*
** display_it.c for print in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:08:44 2015 huy le
** Last update Sun Apr 12 22:09:12 2015 huy le
*/

#include "my_fprintf.h"

int	my_printstr(const int fd, va_list arg_list)
{
  char	*str;

  str = va_arg(arg_list, char *);
  if (str == 0)
    return (my_fputstr(fd, "(null)"));
  return (my_fputstr(fd, str));
}

int	display_it(const int fd, const char *fmt)
{
  if (fmt[0] == '%' && fmt[1] == '%')
    return (my_fputchar(fd, '%'));
  return (my_fputchar(fd, fmt[0]));
}
