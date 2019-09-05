/*
** my_strcat.c for  in /home/karmes_l/test/tmp_Piscine_C_J07
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 17:00:16 2014 lionel karmes
** Last update Sat Apr 11 18:43:59 2015 huy le
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  if (dest == NULL || src == NULL)
    {
      my_putstr("Error: my_strcat failed\n");
      return (NULL);
    }
  while (dest[j] != '\0')
    {
      j = j + 1;
    }
  while (src[i] != '\0')
    {
      *(dest + j + i) = *(src + i);
      i = i + 1;
    }
  dest[i + j] = '\0';
  return (dest);
}
