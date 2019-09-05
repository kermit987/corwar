/*
** my_put_nbr.c for my_put_nbr in /home/karmes_l/test/tmp_Piscine_C_J03
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  1 16:28:28 2014 lionel karmes
** Last update Mon Mar 23 11:10:44 2015 lionel karmes
*/

int	count_num(long nb)
{
  int	i;

  i = 1;
  while (nb / 10 != 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}

