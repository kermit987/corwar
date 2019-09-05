/*
** call_fct_specified.c for call in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:08:32 2015 huy le
** Last update Sun Apr 12 22:08:33 2015 huy le
*/

#include "my_fprintf.h"

int	call_fct_specified(const int fd, t_specifier *specifier,
			   const char *format, va_list arg_list)
{
  short	i;

  i = 0;
  while (specifier[i].specifier)
    {
      if (specifier[i].specifier == *format)
	return (specifier[i].fct_ptr(fd, arg_list));
      i = i + 1;
    }
  return (display_it(fd, format - 1));
}
