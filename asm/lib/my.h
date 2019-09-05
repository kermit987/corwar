/*
** my.h for  in /home/karmes_l/test/tmp_Piscine_C_J09
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  9 15:22:30 2014 lionel karmes
** Last update Sun Apr 12 21:20:46 2015 lionel karmes
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <unistd.h>

char		*convert_base(char *, char *, char *);
int		count_num(long nb);
int		my_charisnum(char);
void		my_fputchar(int, char);
void		my_putchar(char);
void		my_putcharerror(char);
void		my_putnbr(long);
void		my_swap(int *, int *);
void		my_putstr(char *);
void		my_putstrerror(char *);
int		my_strlen(char *);
int		my_getnbr(char *);
void		my_sort_int_tab(int *, int);
char		*mu_strcpy(char *, char *);
char		*mu_strcpy3(char *, char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_strncpy2(char *, char *, int, int);
char		*my_revstr(char *);
char		*my_strstr(char *, char *);
int		my_charstr(char, char *);
int		my_strstr2(char *, char *);
char		*my_strcpy(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int n);
char		*my_strupcase(char *);
char		*my_strlowcase(char *);
char		*mystrcapitalize(char *);
int		my_str_isalpha(char *);
int		my_str_isnum(char *);
int		my_str_isnum2(char *, int, int);
int		mu_str_islower(char *);
int		my_str_isupper(char *);
int		my_str_isprintable(char *);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
int		my_strlcat(char *, char *, int);
unsigned long	pow_10(int);
int		power(unsigned long, unsigned long);
char		**my_strnum_to_wordtab(char *);
void		*pmalloc(int);
char		*get_next_line(int);
char		*replace_by_argument(char *str, char current_av, char new_av);
char		*before_word(char *str);
char		*supp_space(char *str, int i, char before, char after);
char		*epur_str(char *str);
char		*remove_comment(char *str, char argument);
char		*fidding_argument(char *argument, char *str, int *i);
char		*fidding_instruction(char *instruction, char *str, int *i);
int		valide_or_not(char *instruction);
int		split_instruction(char *str, int *pc);

# define SIZE_WIN_X (1000)
# define SIZE_WIN_Y (1000)

#endif /* !MY_H_ */
