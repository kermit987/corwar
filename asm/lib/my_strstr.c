/*
** my_strstr.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 17:22:17 2014 lionel karmes
** Last update Sat Apr  4 15:12:24 2015 Steven Loo Fat
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (to_find[j] != '\0')
    j = j + 1;
  while (str[i] != '\0')
    {
      k = 0;
      while (k < j && str[i + k] == to_find[k])
	{
	  k = k + 1;
	  if (k == j)
	    return (to_find);
	}
      i = i + 1;
    }
  return (0);
}
