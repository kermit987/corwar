/*
** check_instruction.c for  in /home/loofat_s/rendu/coreware_asm/asm/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Sun Mar 29 13:32:21 2015 Steven Loo Fat
** Last update Sat Apr 11 19:54:58 2015 huy le
*/

#include "my.h"
#include "op.h"

char	*fidding_argument(char *argument, char *str, int *i)
{
  int	tmp_i;

  tmp_i = *i;
  while (str[*i] != '\0')
    (*i)++;
  if ((argument = malloc(sizeof(char) * (*i + 1))) == NULL)
    {
      my_putstr("Error: malloc in check_instruction function failed\n");
      return (NULL);
    }
  argument = my_strncpy(argument, &str[tmp_i + 1], *i);
  return (argument);
}

char	*fidding_instruction(char *instruction, char *str, int *i)
{
  while (str[*i] != ' ' && str[*i] != '\0' && str[*i] != ':')
    (*i)++;
  if ((instruction = malloc(sizeof(char) * (*i + 1))) == NULL)
    {
      my_putstr("Error: malloc in check_instruction function failed\n");
      return (NULL);
    }
  instruction = my_strncpy(instruction, str, *i);
  return (instruction);
}

int	valid_or_not(char *instruction)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, instruction) == 0)
	return (i);
      i++;
    }
  my_putstr("Error: invalid instruction\n");
  return (-1);
}

char	*remove_space(char *str)
{
  int	i;
  int	tmp_i;

  i = 0;
  tmp_i = 0;
  while (str[i] != '\0')
    {
      if (i > 2 && str[i] == ':' && str[i - 1] == ' ' && str[i - 2] == '%')
	{
	  tmp_i = i;
	  while (str[tmp_i] != '\0')
	    {
	      str[tmp_i] = str[tmp_i + 1];
	      tmp_i++;
	    }
	  i = 0;
	}
      i++;
    }
  return (str);
}

int	split_instruction(char *str, int *pc, t_list **list_op_code)
{
  int	i;
  int	code;
  char	*instruction;
  char	*argument;

  i = 0;
  instruction = NULL;
  argument = NULL;
  if ((instruction = fidding_instruction(instruction, str, &i)) == NULL)
    return (-1);
  if ((code = valid_or_not(instruction)) == -1)
    {
      free(instruction);
      return (-1);
    }
  free(instruction);
  if (str[i] == '\0')
    return (msg_error_args(op_tab[code].code));
  if ((argument = fidding_argument(argument, str, &i)) == NULL)
    return (-1);
  argument = remove_space(argument);
  return (parsing_args(pc, op_tab[code].code, argument, list_op_code));
}
