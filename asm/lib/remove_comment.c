/*
** remove_commentaire.c for  in /home/loofat_s/rendu/CPE_2014_corewar/asm/lib
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Tue Mar 24 16:10:37 2015 Steven Loo Fat
** Last update Sun Apr 12 21:21:29 2015 lionel karmes
*/

#include "my.h"

char	*remove_comment(char *str, char argument)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != argument)
    i++;
  str[i] = '\0';
  return (str);
}
