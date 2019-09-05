/*
** my_str_to_wordtab.c for  in /home/karmes_l/test/tmp_Piscine_C_J08
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  9 12:31:23 2014 lionel karmes
** Last update Sat Apr 11 18:41:00 2015 huy le
*/

#include "my.h"

int	nbr_words(char *str)
{
  int	i;
  int	j;
  int	isn_num;

  i = 0;
  j = 0;
  isn_num = 0;
  if (str[0] != ' ')
    j = j + 1;
  while (str[i] != 0)
    {
      if (str[i] == ' ')
	isn_num = 1;
      if (str[i + 1] != 0)
	{
	  if (isn_num == 1 && str[i + 1] != ' ')
	    {
	      isn_num = 0;
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
  return (j);
}

int	size_word(int i, char *str)
{
  int	j;

  j = 0;
  while (str[i] != '\0' && str[i] != ' ')
    {
      j = j + 1;
      i = i + 1;
    }
  return (j);
}

char	**size_table_char(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**word;

  k = 0;
  if ((word = pmalloc((1 + nbr_words(str)) * sizeof(char *))) == NULL)
    exit(0);
  i = 0;
  while (str[i] != '\0')
    {
      j = size_word(i, str);
      if (j > 0)
	{
	  i = i + j;
	  if ((word[k++] = pmalloc(sizeof(char) * (j + 1))) == NULL)
	    exit(0);
	}
      else
	  i = i + j + 1;
    }
  if ((word[k] = pmalloc(sizeof(char) * 1)) == NULL)
    exit(0);
  word[k] = '\0';
  return (word);
}

char	**my_strnum_to_wordtab(char *str)
{
  char	**word;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  word = size_table_char(str);
  while (str[i] != '\0')
    {
      j = 0;
      while (str[i + j] != ' ' && str[i + j] != '\0')
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
