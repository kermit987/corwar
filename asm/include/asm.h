/*
** asm.h for  in /home/karmes_l/Projets/Prog_Elem/Corewar/CPE_2014_corewar/asm
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Mar 23 12:16:50 2015 lionel karmes
** Last update Sat Apr 11 19:50:02 2015 huy le
*/

#ifndef ASM_H_
# define ASM_H_

# include "op.h"

# define PROG_NAME	(1)
# define COMMENT	(2)

typedef struct	s_list
{
  int		size;
  void		*l_start;
  void		*l_end;
  int		what_element;
}		t_list;

typedef struct		s_label
{
  int			position;
  char			*name;
  struct s_label	*e_next;
  struct s_label	*e_prev;
}			t_label;

typedef struct		s_op_code
{
  char			o_code;
  char			o_param;
  struct s_op_code	*e_next;
  struct s_op_code	*e_prev;
}			t_op_code;

typedef struct		s_lists
{
  t_list		*list_label;
  t_list		*list_op_code;
}			t_lists;

int		assembler(int, char **);
int		msg_error_open(char *);
int		o_trunc_error(char *, int);
int		init_header(header_t *, int, int *);
void		msg_warning_header_overflow(int);
int		msg_error_header(header_t *);
int		msg_error_header_name();
char		*str_pure(char *);
void		update_header_size(int *, char *);
void		my_put_in_list_end(t_list **, void *);
void		my_put_in_list_start(t_list **, void *);
t_list		*new_list();
void		remove_list(t_list **);
void		put_end_element_label(t_list **, t_label *);
void		put_start_element_label(t_list **, t_label *);
void		remove_list_label(t_label *);
void		put_end_element_op_code(t_list **, t_op_code *);
void		put_start_element_op_code(t_list **, t_op_code *);
void		remove_list_op_code(t_op_code *);
t_label		*find_element_label(t_list *, char *);
char		*supp_space(char *str, int i, char before, char after);
char		*epur_str(char *str);
int		init_label(header_t *, t_lists *, int, int *);
int		msg_error_label(char *);
int		msg_error_label_unknown(char *);
int		msg_error_label_multiple(char *);
int		msg_error_args(char);
int		msg_error_args_chars(char *);
int		msg_error_args_type(args_type_t);
int		msg_error_line(int);
int		msg_error_args_dir(char *);
int		msg_warning_args_size(char *, int);
int		msg_error_args_reg(char *);
int		msg_error_args_type(args_type_t);
int		init_op_code(t_op_code **, char);
void		update_op_code(t_op_code *, int, args_type_t);
int		valid_args_dir(char *);
int		valid_args_ind(char *);
int		valid_args_reg(char *);
int		parsing_args(int *, char, char *, t_list **);
int		split_instruction(char *, int *, t_list **);
int		define_octal_value(char);
int		write_fd(char *, t_list *, t_op_code *, int);
void		write_type(int, int, int);
int		write_file_cor(int, int);
int		write_file_cor_body(int, int, t_lists *, int);
int		split_argument(char **, t_list *, t_op_code *, int);
int		my_str_islabel(char *, int, int);
void		delete_n_caractere(char *str, int nb);
int		remove_tag_buff(char **, char **);
int		init_lists(t_lists *);
int		remove_lists(t_lists *);

# define LABEL (1)
# define OP_CODE (2)

#endif /* ASM_H_ */
