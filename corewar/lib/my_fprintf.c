/*
** my_fprintf.c for call in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:11:03 2015 huy le
** Last update Sun Apr 12 22:11:04 2015 huy le
*/

#include "my_fprintf.h"
#include <stdlib.h>

void	initialize(t_specifier *specifiers)
{
  char	*specifier;
  int	i;

  i = 0;
  specifier = "diouxXscpSb";
  while (i < NBR_SPECIFIER - 1)
    {
      specifiers[i].specifier = specifier[i];
      i = i + 1;
    }
  specifiers[i].specifier = '\0';
  specifiers[0].fct_ptr = &my_printnbr;
  specifiers[1].fct_ptr = &my_printnbr;
  specifiers[2].fct_ptr = &my_printnbr_o;
  specifiers[3].fct_ptr = &my_printnbr_u;
  specifiers[4].fct_ptr = &my_printnbr_x;
  specifiers[5].fct_ptr = &my_printnbr_X;
  specifiers[6].fct_ptr = &my_printstr;
  specifiers[7].fct_ptr = &my_printchar;
  specifiers[8].fct_ptr = &my_printadr;
  specifiers[9].fct_ptr = &my_printStr;
  specifiers[10].fct_ptr = &my_printnbr_b;
  specifiers[11].fct_ptr = NULL;
}

int		my_fprintf(const int fd, const char *format, ...)
{
  va_list	arg_list;
  t_specifier	specifiers[NBR_SPECIFIER];
  int		ret;
  unsigned int	i;

  va_start(arg_list, format);
  initialize(specifiers);
  if (format == NULL)
    return (0);
  ret = 0;
  i = 0;
  while (format[i])
    if (format[i] == '%')
      {
	ret = call_fct_specified(fd, specifiers, &format[i + 1], arg_list);
	i = i + 2;
      }
    else
      ret += display_it(fd, &format[i++]);
  va_end(arg_list);
  return (ret);
}
