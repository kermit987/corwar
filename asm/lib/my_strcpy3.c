/*
** my_strcpy3.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Mar 26 11:45:28 2015 lionel karmes
** Last update Thu Mar 26 11:52:26 2015 lionel karmes
*/

#include "my.h"

char	*my_strcpy3(char *dest, char *src, char *delimit)
{
  int	i;

  i = 0;
  while (src[i] && my_charstr(src[i], delimit))
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
