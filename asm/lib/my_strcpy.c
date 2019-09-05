/*
** my_strcpy.c for  in /home/karmes_l/test/tmp_Piscine_C_J06
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Oct  6 14:27:54 2014 lionel karmes
** Last update Tue Mar 24 17:00:58 2015 Steven Loo Fat
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i= 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
