/*
** my_strdup.c for strdup in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:11:58 2015 huy le
** Last update Sun Apr 12 22:11:59 2015 huy le
*/

#include "utils.h"
#include <stdlib.h>

char	*my_strdup(const char *src)
{
  char	*new;

  if (!(new = fmalloc(sizeof(char) * (my_strlen(src) + 1))))
    return (NULL);
  my_strcpy(new, src);
  return (new);
}
