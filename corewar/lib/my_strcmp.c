/*
** my_strcmp.c for strcm in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:11:44 2015 huy le
** Last update Sun Apr 12 22:11:45 2015 huy le
*/

int		my_strcmp(char *s1, char *s2)
{
  unsigned int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while ((s1[i] == s2[i]) && (s1[i] != '\0'))
    i = i + 1;
  return (s1[i] - s2[i]);
}

int		my_strcncmp(char *s1, char *s2, unsigned int n)
{
  unsigned int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while ((s1[i] == s2[i]) && (i < n - 1))
    i = i + 1;
  return (s1[i] - s2[i]);

}

int		my_strncmp(char *s1, char *s2, unsigned int n)
{
  unsigned int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (((s1[i] == s2[i]) && (s1[i] != '\0')) && (i < n - 1))
    i = i + 1;
  return (s1[i] - s2[i]);
}
