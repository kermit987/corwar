/*
** power.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  8 18:01:33 2014 lionel karmes
** Last update Sat Apr 11 17:34:25 2015 lionel karmes
*/

int		power(unsigned long nb, unsigned long pow)
{
  unsigned int	i;
  int		nb_tmp;

  i = 1;
  nb_tmp = nb;
  while (i < pow)
    {
      nb = nb * nb_tmp;
      i = i + 1;
    }
  if (pow == 0)
    return (1);
  return (nb);
}
