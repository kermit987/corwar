/*
** my_strtablen.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell1
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Jan 13 10:56:48 2015 lionel karmes
** Last update Wed Jan 28 00:27:52 2015 lionel karmes
*/

#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != 0)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}

int	my_strtablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != 0)
    i++;
  return (i);
}
