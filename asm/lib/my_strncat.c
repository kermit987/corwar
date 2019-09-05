/*
** my_strncat.c for  in /home/karmes_l/test/tmp_Piscine_C_J07
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Wed Oct  8 12:05:28 2014 lionel karmes
** Last update Thu Mar 26 10:50:18 2015 lionel karmes
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  while (dest[j] != '\0')
    {
      j = j + 1;
    }
  while (src[i] != '\0' && i < nb)
    {
      *(dest + j + i) = *(src + i);
      i = i + 1;
    }
  dest[j + i] = '\0';
  return (dest);
}
