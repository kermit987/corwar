/*
** pow_10.c for  in /home/karmes_l/test/my_function
** 
OP** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  9 08:50:35 2014 lionel karmes
** Last update Sat Apr 11 17:34:36 2015 lionel karmes
*/

long	pow_10(int i)
{
  int	c;
  long	nb;

  c = 0;
  nb = 1;
  while (c < i)
    {
      nb = (long)nb * 10;
      c = c + 1;
    }
  return (nb);
}
