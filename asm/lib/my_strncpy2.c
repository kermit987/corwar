/*
** my_strncpy.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 16:11:48 2014 lionel karmes
** Last update Mon Mar 23 21:46:20 2015 lionel karmes
*/

char	*my_strncpy2(char *dest, char *src, int k, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  i = k;
  while (i < k + n && src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
