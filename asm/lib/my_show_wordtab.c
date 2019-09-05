/*
** my_show_wordtab.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Oct 10 19:28:03 2014 lionel karmes
** Last update Tue Dec  2 18:44:42 2014 lionel karmes
*/

#include "my.h"

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
