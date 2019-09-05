/*
** my_str_islower.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 10:32:21 2014 lionel karmes
** Last update Tue Oct  7 10:35:33 2014 lionel karmes
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*(str + i) < 97 || *(str + i) > 122)
	return (0);
      i = i + 1;
    }
  return (1);
}
