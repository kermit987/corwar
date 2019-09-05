/*
** get_next_line.h for  in /home/karmes_l/Projets/Prog_Elem/get_next_line
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sat Nov 15 14:28:14 2014 lionel karmes
** Last update Sat Apr 11 17:24:38 2015 lionel karmes
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

# define SIZE_TO_READ (2)

typedef	struct	s_line
{
  int		c;
  int		len;
  char		*str_line;
}		t_line;

char	*get_next_line(const int fd);
void		*pmalloc(int);

#endif /* !GET_NEXT_LINE_ */
