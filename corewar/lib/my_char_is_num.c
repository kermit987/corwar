/*
** my_char_is_num.c for char in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:06:23 2015 huy le
** Last update Sun Apr 12 22:06:24 2015 huy le
*/

int	my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
