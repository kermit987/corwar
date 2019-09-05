/*
** my_putchar.c for putchar in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:11:22 2015 huy le
** Last update Sun Apr 12 22:11:22 2015 huy le
*/

#include <unistd.h>

int	my_putchar(const char c)
{
  return (write(1, &c, 1));
}

int	my_fputchar(const int fd, const char c)
{
  return (write(fd, &c, 1));
}
