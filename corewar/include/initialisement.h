/*
** initialisement.h for corewar in /home/metz_a/brouillons/corewar
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Thu Apr  9 12:43:08 2015 Aurélien Metz
** Last update Sun Apr 12 21:47:07 2015 huy le
*/

#ifndef INITIALISEMENT_H_
# define INITIALISEMENT_H_

# include "champion.h"

# define FORMAT_INT		("0123456789")
# define WRONG_ADDR		("\033[31mWrong address: '%s'\n\033[0m")
# define FORMAT_PN		("1234")
# define WRONG_COR		("\033[31m'%s', should be a .cor\n\033[0m")
# define NBR_CHAMP		(4)
# define WRONG_PN		("\033[31mWrong prog number: '%s'\n\033[0m")
# define INV_DUMP		("\033[31m'%s' invalid number of cy\
cle\n\033[0m")
# define MAP_SIZE		(6 * 1024)
# define MAX_ARGS		(15)
# define MIN_ARGS		(2)
# define NBR_REGS		(16)
# define ERROUT			(2)
# define USAGE			("\033[31m--- USAGE ---\n./corewar (-dum\
p nbr_cycle) [(-a addr -n prog_nbr) champion\n\033[0m]")
# define DUMP			("-dump")
# define COR			(".cor")
# define IDS			("\001\002\003\004")
# define N			("-n")
# define A			("-a")

/*
** prototypes
*/
char	*my_strdup(char *str);
void	my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
int	my_atoi(char *nb);
int	str_in_format(char *str, char *format);
int	init_champion(t_champ *champion, char **av,
		      char ids[NBR_CHAMP + 1], char map[MAP_SIZE]);
int	check_arg(t_champ *champion, char **av, char *arg, char ids[NBR_CHAMP]);
int	get_ids(char ids[NBR_CHAMP], char pn);
void	init_regs(int regs[NBR_REGS], int id);
int	my_fprintf(const int fd, const char *str, ...);
int	my_strlen(char *str);
int	read_file(t_champ *champion, char *file, char map[MAP_SIZE]);
int	check_dump(char **av);

#endif /* !INITIALISEMENT_H_ */
