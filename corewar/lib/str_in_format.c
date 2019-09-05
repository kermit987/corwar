/*
** str_in_format.c for lib in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 13:09:18 2015 Aurélien Metz
** Last update Thu Apr  9 13:09:42 2015 Aurélien Metz
*/

int	str_in_format(char *str, char *format)
{
  int	i[2];
  int	valid;

  if (!str)
    return (0);
  i[0] = 0;
  while (str[i[0]])
    {
      valid = 0;
      i[1] = 0;
      while (format[i[1]])
	if (str[i[0]] == format[i[1]++])
	  valid = 1;
      if (!valid)
	return (0);
      i[0]++;
    }
  return (1);
}
