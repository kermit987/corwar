/*
** load_champions.h for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 17:03:23 2015 Aurélien Metz
** Last update Sun Apr 12 22:01:39 2015 huy le
*/

#ifndef LOAD_CHAMPIONS_H_
# define LOAD_CHAMPIONS_H_

# include "champion.h"
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE_FOR_INSTRUCTIONS	(2192)
# define NBR_CHAMP		(4)
# define MAP_SIZE		(6 * 1024)
# define OVERLAP		("\033[31mOverlap detected !\n\033[0m")
# define ERROUT			(2)

typedef struct	s_blp
{
  int		pos;
  int		len;
}		t_blp;

/*
** prototypes
*/
int	        load_champ(t_champ *champion, char map[MAP_SIZE]);
int		get_loaded(t_champ *champion, int fd, char map[MAP_SIZE]);
int		my_fprintf(const int fd, const char *str, ...);
void		*fmalloc(int size);
int		xread(int fd, char *buf, int len);

#endif /* !LOAD_CHAMPIONS_H_ */
