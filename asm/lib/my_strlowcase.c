/*
** my_strlowcase.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 09:40:34 2014 lionel karmes
** Last update Sat Apr 11 17:33:24 2015 lionel karmes
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*(str + i) > 64 && *(str + i) < 91)
	*(str + i) = *(str + i) + 32;
      i = i + 1;
    }
  return (str);
}
