/*
** my_str_isnum.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 10:25:34 2014 lionel karmes
** Last update Tue Oct  7 10:30:25 2014 lionel karmes
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*(str + i) < 48 || *(str + i) > 57)
	return (0);
      i = i + 1;
    }
  return (1);
}
