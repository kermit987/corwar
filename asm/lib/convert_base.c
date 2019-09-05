/*
** convert_base.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  8 17:16:10 2014 lionel karmes
** Last update Sat Apr 11 18:54:48 2015 huy le
*/

#include "my.h"

int	size_table(long nbr, long nbr_base)
{
  int	i;

  i = 1;
  while (nbr / nbr_base > 0)
    {
      nbr = nbr / nbr_base;
      i = i + 1;
    }
  return (i);
}

int	value_from_base(char nbr, char *base_from)
{
  int	i;

  i = 0;
  while (base_from[i] != '\0')
    {
      if (*(base_from + i) == nbr)
	return (i);
      i = i + 1;
    }
  return (0);
}

long	convert_base_from(char *nbr, char *base_from)
{
  long	nbr_base;
  long	nbr_base_from;
  long	nbr_b10;
  int	i;
  long	value_base;

  i = 0;
  nbr_b10 = 0;
  nbr_base = my_strlen(nbr);
  nbr_base_from = my_strlen(base_from);
  while (nbr_base > 0)
    {
      nbr_base = nbr_base - 1;
      value_base = value_from_base(nbr[i], base_from);
      nbr_b10 = nbr_b10 + value_base * power(nbr_base_from, nbr_base);
      i = i + 1;
    }
  return (nbr_b10);
}

char	*convert_base_to(long nbr, char *base)
{
  long	nbr_base;
  long	rest;
  int	i;
  char	*str;

  nbr_base = my_strlen(base);
  i = size_table(nbr, nbr_base);
  if ((str = pmalloc(sizeof(char) * (i + 1))) != NULL)
    {
      str[i] = '\0';
      i = 0;
      while (nbr / nbr_base > 0)
	{
	  rest = nbr % nbr_base;
	  nbr = nbr / nbr_base;
	  *(str + i) = base[rest];
	  i = i + 1;
	}
      rest = nbr % nbr_base;
      *(str + i) = base[rest];
    }
  return (str);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  long	nb_b10;
  char	*str_positive;
  char	*str_negative;
  int	i;

  if (my_strlen(base_from) <= 1 || my_strlen(base_to) <= 1)
    return (0);
  nb_b10 = convert_base_from(nbr, base_from);
  str_positive = convert_base_to(nb_b10, base_to);
  my_revstr(str_positive);
  if (nbr[0] == '-')
    {
      if ((str_negative = pmalloc(my_strlen(str_positive) + 1)) != NULL)
	{
	  *(str_negative + 0) = '-';
	  i = 1;
	  while (str_negative[i] != '\0')
	    *(str_negative + i) = *(str_positive + i - 1);
	}
      free(str_positive);
      return (str_negative);
    }
  return (str_positive);
}
