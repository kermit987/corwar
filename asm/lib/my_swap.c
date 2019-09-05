/*
** my_swap.c for my_swap in /home/karmes_l/test/tmp_Piscine_C_J04
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  2 10:54:40 2014 lionel karmes
** Last update Fri Dec  5 12:18:03 2014 lionel karmes
*/

void	my_swap(int *a, int *b)
{
  int	tmp_b;

  tmp_b = *b;
  *b = *a;
  *a = tmp_b;
}
