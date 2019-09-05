/*
** my_atoi_base.c for atoi in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:06:33 2015 huy le
** Last update Sun Apr 12 22:06:34 2015 huy le
*/

#include "utils.h"

int	my_atoi_base(char *str, char *base)
{
  int	nb;
  int	i[2];

  i[0] = 0;
  nb = 0;
  while (str[i[0]])
    {
      i[1] = 0;
      while (str[i[0]] != base[i[1]])
	i[1]++;
      nb =  my_strlen(base) * nb + i[1];
      i[0]++;
    }
  return (nb);
}

int	my_uatoi_base(unsigned char *str, char *base)
{
  int	nb;
  int	i[2];

  i[0] = 0;
  nb = 0;
  while (str[i[0]])
    {
      i[1] = 0;
      while (str[i[0]] != base[i[1]])
	i[1]++;
      nb =  my_strlen(base) * nb + i[1];
      i[0]++;
    }
  return (nb);
}

int	my_unatoi_base(unsigned char *str, char *base, int n)
{
  int	nb;
  int	i[2];

  i[0] = 0;
  nb = 0;
  while (i[0] < n)
    {
      i[1] = 0;
      while (str[i[0]] != base[i[1]])
	i[1]++;
      nb =  my_strlen(base) * nb + i[1];
      i[0]++;
    }
  return (nb);
}
