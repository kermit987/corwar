/*
** my_strcmp.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 19:34:18 2014 lionel karmes
** Last update Mon Oct  6 22:40:48 2014 lionel karmes
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s2[j] != '\0')
    {
      j = j + 1;
    }
  while (s1[i] != '\0')
    {
      if (s1[i] - s2[i] != 0)
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  if (s2[i] != '\0')
    return (-s2[i]);
  else
    return (0);
}
