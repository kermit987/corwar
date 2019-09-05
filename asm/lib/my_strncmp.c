/*
** my_strncmp.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 22:22:29 2014 lionel karmes
** Last update Sat Oct 11 09:17:36 2014 lionel karmes
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < n && s1[j] != '\0')
    {
      j = j + 1;
    }
  while (i < n && s1[i] != '\0')
    {
      if (s1[i] - s2[i] != 0)
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
