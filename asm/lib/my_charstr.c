/*
** my_charstr.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Mar 26 11:48:03 2015 lionel karmes
** Last update Sat Apr  4 15:15:11 2015 Steven Loo Fat
*/

int	my_charstr(char c, char *str)
{
  int	i;
  int	valid;

  i = 0;
  valid = 0;
  while (str[i])
    {
      if (c == str[i])
	valid = 1;
      i++;
    }
  if (valid)
    return (1);
  return (0);
}
