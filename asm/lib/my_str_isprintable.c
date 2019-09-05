/*
** my_str_isprintable.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 10:49:34 2014 lionel karmes
** Last update Wed Oct  8 10:44:56 2014 lionel karmes
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*(str + i) < 32 || *(str + i) > 126)
	return (0);
      i = i + 1;
    }
  return (1);
}
