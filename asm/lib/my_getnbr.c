/*
** my_getnbr.c for my_getnbr in /home/karmes_l/test/tmp_Piscine_C_J04
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  2 21:48:41 2014 lionel karmes
** Last update Sat Apr 11 18:58:33 2015 huy le
*/

#include "my.h"

int	my_strlen_num(char *str)
{
  int	c;
  int	len;
  short	n_a_n;

  c = 0;
  len = 0;
  n_a_n = 0;
  while (*(str + c) != '\0')
    {
      if (n_a_n == 1 && (*(str + c) < 48 || *(str + c) >= 58))
	{
	  n_a_n = 2;
	}
      if (*(str + c) >= 48 && *(str + c) < 58 && n_a_n != 2)
	{
	  len = len + 1;
	  n_a_n = 1;
	}
      c = c + 1;
    }
  return (len);
}

int	my_nb(char *str, int nb_num)
{
  int	nb;
  int	i;
  int	signe;

  i = 0;
  nb = 0;
  signe = 1;
  while (*(str + i) != '\0' && nb_num > 0)
    {
      if (*(str + i) == '-')
	signe = -signe;
      if (*(str + i) >= 48 && *(str + i) < 58)
	{
	  if (nb_num <= 10)
	    {
	      nb = nb + (*(str + i) - 48) * pow_10(nb_num - 1);
	      nb_num = nb_num - 1;
	    }
	}
      i = i + 1;
    }
  nb = nb * signe;
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	nb_num;

  nb_num = my_strlen_num(str);
  nb = my_nb(str, nb_num);
  return (nb);
}
