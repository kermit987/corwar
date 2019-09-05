/*
** epur_str.c for  in /home/loofat_s/rendu/coreware_asm/asm/lib
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Thu Mar 26 13:59:41 2015 Steven Loo Fat
<<<<<<< HEAD
** Last update Sun Apr 12 21:17:52 2015 huy le
=======
** Last update Sun Apr 12 21:21:01 2015 lionel karmes
>>>>>>> e165cf65fcddf243285828d8872fcaa43a761a24
*/

#include "my.h"

char	*before_word(char *str)
{
  int	i;

  i = 0;
  if (str[0] == ' ')
    {
      while (str[i] != '\0')
	{
	  str[i] = str[i + 1];
	  i++;
	}
    }
  return (str);
}

char	*supp_space(char *str, int i, char before, char after)
{
  while (str[i] != '\0')
    {
      if (str[i] == before && str[i + 1] == after)
	{
	  while (str[i] != '\0')
	    {
	      str[i] = str[i + 1];
	      i++;
	    }
	  i = 0;
	}
      if (str[i] == before && str[i + 1] == '\0')
	{
	  while (str[i] != '\0')
	    {
	      str[i] = str[i + 1];
	      i++;
	    }
	  i = 0;
	}
      str = before_word(str);
      i++;
    }
  return (str);
}

char	*epur_str(char *str)
{
  int	i;

  i = 0;
  str = remove_comment(str, '#');
  str = replace_by_argument(str, '\t', ' ');
  str = supp_space(str, i, ' ', ' ');
  return (str);
}
