/*
** my_puterror.c for puterror in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:05:05 2015 huy le
** Last update Sun Apr 12 22:05:06 2015 huy le
*/

#include "utils.h"
#include <unistd.h>

int	my_puterror(const char *str)
{
  if (str == NULL)
    return (0);
  return (write(2, str, my_strlen(str)));
}

int	my_putnerror(const char *str, const int n)
{
  if (str == NULL)
    return (0);
  return (write(2, str, n));
}
