/*
** my_fprintf.h for lib in /home/metz_a/rendu/System unix/PSU_2014_minishell2/lib
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Sat Mar 14 13:07:49 2015 Aurélien Metz
** Last update Sat Mar 14 13:12:22 2015 Aurélien Metz
*/

#ifndef MY_FRPINTF_H_
# define MY_FPRINTF_H_

# include <stdarg.h>
# include "utils.h"

# define NBR_SPECIFIER		(12)

typedef struct	s_specifier
{
  char		specifier;
  int		(*fct_ptr)(const int fd, va_list);
}		t_specifier;

/*
** prototypes
*/
int		call_fct_specified(const int fd, t_specifier *specifier,
				   const char *format, va_list arg_list);
int		my_printadr(const int fd, va_list arg_list);
int		my_fputnbr_base(const int fd, unsigned long nb, char *base);
int		my_printStr(const int fd, va_list arg_list);
int		my_printnbr_b(const int fd, va_list arg_list);
int		my_printchar(const int fd, va_list arg_list);
int		my_printstr(const int fd, va_list arg_list);
int		display_it(const int fd, const char *fmt);
void		initialize(t_specifier *specifiers);
int		my_fprintf(const int fd, const char *format, ...);
int		my_printnbr_o(const int fd, va_list arg_list);
int		my_printnbr_u(const int fd, va_list arg_list);
int		my_printnbr_x(const int fd, va_list arg_list);
int		my_printnbr_X(const int fd, va_list arg_list);
int		my_printnbr(const int fd, va_list arg_list);

#endif /* !MY_FPRINTF_H_ */
