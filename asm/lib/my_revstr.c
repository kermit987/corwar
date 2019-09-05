/*
** my_revstr.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 16:31:37 2014 lionel karmes
** Last update Sun Dec  7 12:49:59 2014 lionel karmes
*/

char	*my_revstr(char *str)
{
  int	i;
  int	a;
  int	b;
  int	j;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  j = 0;
  i = i - 1;
  while (i > j)
    {
      a = *(str + j);
      b = *(str + i);
      *(str + j) = b;
      *(str + i) = a;
      j = j + 1;
      i = i - 1;
    }
  return (str);
}
