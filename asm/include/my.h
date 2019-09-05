/*
** my.h for  in /home/karmes_l/test/tmp_Piscine_C_J09
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  9 15:22:30 2014 lionel karmes
** Last update Sun Apr 12 21:17:39 2015 huy le
*/

#ifndef MY_H_
# define MY_H_

# include <features.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "asm.h"

# define ABS(v1) ((v1) < 0) ? (-(v1)) : (v1)

char		*convert_base(char *, char *, char *);
int		count_num(long nb);
int		my_charisnum(char);
void		my_fputchar(int, char);
void		my_putchar(char);
void		my_putchar0(char);
void		my_putcharerror(char);
void		my_putnbr(long);
void		my_swap(int *, int *);
void		my_putstr(char *);
void		my_putstr0(char *);
void		my_putstrerror(char *);
int		my_strlen(char *);
int		my_getnbr(char *);
void		my_sort_int_tab(int *, int);
char		*my_strcpy(char *, char *);
char		*my_strcpy3(char *, char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_strncpy2(char *, char *, int, int);
char		*my_revstr(char *);
char		*my_strstr(char *, char *);
char		my_charstr(char, char *);
int		my_strstr2(char *, char *);
char		*my_strdup(char *);
char		*my_strdup2(char *, int, int);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int n);
char		*my_strupcase(char *);
char		*my_strlowcase(char *);
char		*mystrcapitalize(char *);
int		my_str_isalpha(char *);
int		my_str_isnum(char *);
int		mu_str_islower(char *);
int		my_str_isupper(char *);
int		my_str_isprintable(char *);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
int		my_strlcat(char *, char *, int);
int		my_str_isnum2(char *, int , int);
unsigned long	pow_10(int);
int		power(unsigned long, unsigned long);
int		my_putchar2(int);
char		**my_str_to_wordtab(char *, char);
void		*pmalloc(int);
char		*get_next_line(int);
int		my_strtablen(char **);
void		free_tab(char **);
int		argc_define_octal(char code, int type, int position);
int		remove_tag_buff_part_2(char **, char **, char **, int);
int		load_name(char *name, char *str, int i, int name_or_comment);
int		multiple_inclusion(char *name, int name_or_comment);
int		invalid_name_or_comment(int name_or_comment);

#endif /* !MY_H_ */
