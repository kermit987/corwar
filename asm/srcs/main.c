/*
** main.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 11:49:41 2015 lionel karmes
** Last update Sat Apr 11 18:20:25 2015 huy le
*/

#include "my.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    assembler(ac, av);
  else
    my_putstrerror("[ERROR] : usage : /asm file_name[.s] ......\n");
  return (0);
}
