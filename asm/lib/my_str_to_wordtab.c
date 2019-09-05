/*
** my_str_to_wordtab.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  9 12:31:23 2014 lionel karmes
** Last update Sat Apr 11 18:37:27 2015 huy le
*/

#include "my.h"

int	nbr_words(char *str, char delimiter)
{
  int	i;
  int	j;
  int	isn_num;

  i = 0;
  j = 0;
  isn_num = 0;
  if (str[0] != delimiter)
    j = j + 1;
  while (str[i] != 0)
    {
      if (str[i] == delimiter)
	isn_num = 1;
      if (str[i + 1] != 0)
	{
	  if (isn_num == 1 && str[i + 1] != delimiter)
	    {
	      isn_num = 0;
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
  return (j);
}

int	size_word(int i, char *str, char delimiter)
{
  int	j;

  j = 0;
  while (str[i] != '\0' && str[i] != delimiter)
    {
      j = j + 1;
      i = i + 1;
    }
  return (j);
}

char	**size_table_char(char *str, char delimiter)
{
  int	i;
  int	j;
  int	k;
  char	**word;

  k = 0;
  if ((word = malloc((1 + nbr_words(str, delimiter)) * sizeof(char *))) == NULL)
    exit(0);
  i = 0;
  while (str[i] != '\0')
    {
      j = size_word(i, str, delimiter);
      if (j > 0)
	{
	  i = i + j;
	  if ((word[k++] = malloc(sizeof(char) * (j + 1))) == NULL)
	    exit(0);
	}
      else
	  i = i + j + 1;
    }
  word[k] = NULL;
  return (word);
}

char	**my_str_to_wordtab_next(char *str, char delimiter)
{
  char	**word;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  word = size_table_char(str, delimiter);
  while (str[i] != '\0')
    {
      j = 0;
      while (str[i + j] != delimiter && str[i + j] != '\0')
	{
	  word[k][j] = *(str + i + j);
	  j = j + 1;
	}
      if (j > 0)
	{
	  word[k++][j] = '\0';
	  i = i + j;
	}
      else
	i = i + 1;
    }
  return (word);
}

char	**my_str_to_wordtab(char *str, char delimiter)
{
  if (str == NULL || str[0] == '\0')
    return (NULL);
  return (my_str_to_wordtab_next(str, delimiter));
}
