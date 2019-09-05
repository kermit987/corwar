/*
** fmalloc.c for malloc in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:06:54 2015 huy le
** Last update Sun Apr 12 22:06:55 2015 huy le
*/

#include "utils.h"
#include <stdlib.h>

void	*fmalloc(int bytes)
{
  void	*tmp;

  if (!(tmp = malloc(bytes)))
    (void)my_puterror("could not alloc\n");
  return (tmp);
}
