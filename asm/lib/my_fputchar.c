/*
** my_fputchar.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Apr  1 14:19:47 2015 lionel karmes
** Last update Sat Apr 11 17:31:39 2015 lionel karmes
*/

#include <unistd.h>

void	my_fputchar(int fd, char c)
{
  (void)write(fd, &c, 1);
}
