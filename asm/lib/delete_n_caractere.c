/*
** delete_n_caractere.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sun Apr  5 18:49:05 2015 lionel karmes
** Last update Sat Apr 11 18:54:09 2015 huy le
*/

void	delete_n_caractere(char *str, int nb)
{
  int	i;
  int	t;

  t = 0;
  while (t < nb)
    {
      i = 0;
      while (str[i] != '\0')
	{
	  str[i] = str[i + 1];
	  i++;
	}
      t++;
    }
}
