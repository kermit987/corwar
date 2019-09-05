/*
** my_str_to_wordtab.c for strwordtab in /home/le_n/rendu/progElem/CPE_2014_corewar/corewar/lib
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sun Apr 12 22:12:09 2015 huy le
** Last update Sun Apr 12 22:12:20 2015 huy le
*/

#include "utils.h"
#include <stdlib.h>

int	countword(const char *str, char cond)
{
  int	word;
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == cond)
	{
	  word = word + 1;
	  i = i + 1;
	}
      while (str[i] != cond && str[i])
	i = i + 1;
    }
  return (word + 1);
}

char	**my_str_to_wordtab(char *str, char cond)
{
  char	**wordtab;
  int	word;
  int	i;

  i = 0;
  word = 0;
  if (!str)
    return (NULL);
  if (!(wordtab = fmalloc(sizeof(char *) * (countword(str, cond) + 1))))
    return (NULL);
  while (str[i])
    {
      while (str[i] == cond)
	str[i++] = 0;
      wordtab[word] = str + i;
      while (str[i] != cond && str[i])
	i = i + 1;
      word = word + 1;
    }
  wordtab[word] = NULL;
  return (wordtab);
}
