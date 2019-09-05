/*
** my_strcpy.c for strcpy in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:04:05 2015 huy le
** Last update Sun Apr 12 22:13:50 2015 huy le
*/

#include <stdlib.h>

void		my_strncpy(char *dest, const char *src, unsigned int nb)
{
  unsigned int	i;

  if (dest == NULL || src == NULL)
    return ;
  i = 0;
  while ((src[i] != '\0') && (i < nb))
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
}

void		my_strcpy(char *dest, const char *src)
{
  unsigned int	i;

  if (dest == NULL || src == NULL)
    return ;
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
}
