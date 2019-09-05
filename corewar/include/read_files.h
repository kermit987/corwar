/*
** read_files.h for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 15:13:40 2015 Aurélien Metz
** Last update Sun Apr 12 21:37:55 2015 huy le
*/

#ifndef READ_FILES_H_
# define READ_FILES_H_

# include "champion.h"
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_MAGIC		("\033[31mWrong magic, magic should be \
: \"\\0\\352\\203\\363\"\n\033[0m")
# define INT_SIZE		(4)
# define MAP_SIZE		(6 * 1024)
# define ERROUT			(2)
# define MAGIC			("\0\352\203\363")
# define OPEN			("\033[31mCould not open: '%s'\n\033[0m")
# define READ			("\033[31mCould not read from: '%s'\n\033[0m")
# define BPO			(8)

/*
** prototypes
*/
int	xread(int fd, char *buf, int len);
int	uxread(int fd, unsigned char *buf, int len);
int	my_fprintf(const int fd, const char *str, ...);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strcncmp(char *s1, char *s2, int n);
int	load_champion(t_champ *champion, int fd, char map[MAP_SIZE]);

#endif /* !READ_FILES_H_ */
