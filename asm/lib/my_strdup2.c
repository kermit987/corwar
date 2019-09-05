/*
** my_strdup2.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 17:23:40 2015 lionel karmes
** Last update Sat Apr 11 18:42:35 2015 huy le
*/

#include "my.h"

char	*my_strdup2(char *src, int i, int n)
{
  int	length;
  char	*str;

  if (src == NULL)
    return (NULL);
  length = my_strlen(src) - i;
  if ((str = pmalloc(sizeof(char) * (length + 1))) == NULL)
    {
      my_putstr("Error: malloc in my_strdup2 function failed\n");
      return (NULL);
    }
  my_strncpy2(str, src, i, n);
  return (str);
}
