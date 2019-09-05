/*
** my_strlen.c for my_strlen in /home/karmes_l/test/tmp_Piscine_C_J04
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  2 15:11:21 2014 lionel karmes
** Last update Wed Oct  8 10:45:30 2014 lionel karmes
*/

int	my_strlen(char *str)
{
  int	c;

  c = 0;
  while (*(str + c) != '\0')
    {
      c = c + 1;
    }
  return (c);
}
