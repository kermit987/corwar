/*
** my_strupcase.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 22:50:44 2014 lionel karmes
** Last update Sat Apr 11 17:34:15 2015 lionel karmes
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int	i;
  int	a;

  i = 0;
  while (*(str + i) != '\0')
    {
      a = *(str + i) - 32;
      *(str + i) = a;
      my_putchar(*(str + i));
      i = i + 1;
    }
  return (str);
}
