/*
** utils.h for lib in /home/metz_a/rendu/System unix/PSU_2014_minishell2/lib
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Sat Mar 14 13:12:39 2015 Aurélien Metz
** Last update Sun Apr 12 21:37:07 2015 huy le
*/

#ifndef UTILS_H_
# define UTILS_H_

# define BUFFER_SIZE		(10)
# define ERROUT			(2)
# define READ			("\033[031mcould not read\n\033[0m")

/*
** prototypes
*/
void		*fmalloc(int bytes);
void		line0(char *line, unsigned int size);
char		*my_realloc(int size, char *old);
int		put_read_in_line(char **line, char *buff);
char		*get_next_line(const int fd);
int		my_atoi_base(char *str, char *base);
int		my_unatoi_base(unsigned char *str, char *base, int n);
int		my_atoi(const char *str);
int		my_char_is_num(char c);
int		my_putchar(const char c);
int		my_fputchar(const int fd, const char c);
int		my_puterror(const char *str);
int		my_putnerror(const char *str, const int n);
int		my_putnbr(int nb);
int		my_fputnbr(const int fd, int nb);
int		my_putnstr(const char *str, const int n);
int		my_putstr(const char *str);
int		my_fputstr(const int fd, const char *str);
int		my_fputnstr(const int fd, const char *str, const int n);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, unsigned int n);
void		my_strncpy(char *dest, const char *src, unsigned int nb);
void		my_strcpy(char *dest, const char *src);
char		*my_strdup(const char *src);
unsigned int	my_strlen(const char *str);
int		countword(const char *str, char cond);
char		**my_str_to_wordtab(char *str, char cond);
int		xread(int fd, char *buffer, int len);
int		uxread(int fd, unsigned char *buffer, int len);

#endif /* !UTILS_H_ */
