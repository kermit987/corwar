/*
** my_atoi.c for ati in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:10:52 2015 huy le
** Last update Sun Apr 12 22:10:53 2015 huy le
*/

#include "utils.h"
#include <stdlib.h>

int	my_atoi(const char *str)
{
  int	nb;
  int	neg;
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  nb = 0;
  neg = 0;
  while (str[i] == '-')
    {
      neg = neg + 1;
      i = i + 1;
    }
  while (my_char_is_num(str[i]) == 1)
    nb = 10 * nb + (str[i++] - '0');
  while (neg--)
    nb = -nb;
  return (nb);
}
