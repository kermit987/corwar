/*
** my_strdup.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  8 16:46:51 2014 lionel karmes
** Last update Sat Apr 11 18:59:50 2015 huy le
*/

#include "my.h"

char	*my_strdup(char *src)
{
  int	length;
  char	*str;

  if (src == NULL)
    return (NULL);
  length = my_strlen(src);
  if ((str = pmalloc(sizeof(char) * (length + 1))) == NULL)
    exit(0);
  my_strcpy(str, src);
  return (str);
}
