/*
** my_putstr.c for putstr in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:04:24 2015 huy le
** Last update Sun Apr 12 22:04:26 2015 huy le
*/

#include "utils.h"
#include <unistd.h>

int	my_putnstr(const char *str, const int n)
{
  if (str == NULL)
    return (0);
  return (write(1, str, n));
}

int	my_putstr(const char *str)
{
  if (str == NULL)
    return (0);
  return (write(1, str, my_strlen(str)));
}

int	my_fputstr(const int fd, const char *str)
{
  if (str == NULL)
    return (0);
  return (write(fd, str, my_strlen(str)));
}

int	my_fputnstr(const int fd, const char *str, const int n)
{
  if (str == NULL)
    return (0);
  return (write(fd, str, n));
}
