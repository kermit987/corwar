/*
** my_strcapitalize.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Oct  7 09:53:32 2014 lionel karmes
** Last update Sat Apr 11 17:33:03 2015 lionel karmes
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (*str > 96 && *str < 123)
	*str = *str - 32;
      if (i > 0)
	{
	  if (*(str + i) > 64 && *(str + i) < 91)
	    *(str + i) = *(str + i) + 32;
	}
      i = i + 1;
    }
  return (str);
}
