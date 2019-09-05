/*
** my_charisalpha.c for  in /home/karmes_l/test/my_function
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Oct 10 14:30:49 2014 lionel karmes
** Last update Fri Oct 10 14:32:15 2014 lionel karmes
*/

int	my_charisalpha(char a)
{
  if (a < 65 || a > 122)
    return (1);
  if (a > 90 && a < 97)
    return (1);
  return (0);
}
