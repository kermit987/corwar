/*
** my_strlen.c for strlen in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:03:47 2015 huy le
** Last update Sun Apr 12 22:03:48 2015 huy le
*/

#include <stdlib.h>

unsigned int	my_strlen(const char *str)
{
  if (str == NULL || str[0] == '\0')
    return (0);
  return (my_strlen(str + 1) + 1);
}
