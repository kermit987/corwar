/*
** op.h for header_corewar in /home/le_n/rendu/progElem/CPE_2014_corewar/asm/include
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sat Apr 11 18:15:50 2015 huy le
** Last update Sun Apr 12 21:52:46 2015 huy le
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE		(6*1024)
# define IDX_MOD		(512)
# define MAX_ARGS_NUMBER	(4)

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER		(16)

typedef char	args_type_t;

# define T_REG			(1)
# define T_DIR			(2)
# define T_IND			(4)
# define T_LAB			(8)

typedef struct	op_s
{
   char		*mnemonique;
   char		nbr_args;
   args_type_t	type[MAX_ARGS_NUMBER];
   char		code;
   int		nbr_cycles;
   char		*comment;
}		op_t;

# define IND_SIZE		(2)
# define REG_SIZE		(4)
# define DIR_SIZE		REG_SIZE

extern	op_t	op_tab[];

# define NBR_OP			(16)

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define MAGIC_LENGTH		(4)

typedef struct	header_s
{
   int		magic;
   char		prog_name[PROG_NAME_LENGTH + 1];
   int		prog_size;
   char		comment[COMMENT_LENGTH + 1];
}		header_t;

# define COREWAR_EXEC_MAGIC	(0xea83f3)
# define CYCLE_TO_DIE		(1536)
# define CYCLE_DELTA		(5)
# define NBR_LIVE		(40)

#endif /* !OP_H_ */
