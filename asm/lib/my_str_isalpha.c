/*
** my_str_isalpha.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 10:08:28 2014 lionel karmes
** Last update Tue Oct  7 10:16:09 2014 lionel karmes
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*(str + i) < 65 || *(str + i) > 122)
	return (0);
      if (*(str + i) > 90 && *(str + i) < 97)
	return (0);
      i = i + 1;
    }
  return (1);
}
