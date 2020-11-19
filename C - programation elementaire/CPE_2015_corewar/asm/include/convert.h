/*
** convert.h for convert in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/include/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Mon Mar 21 18:25:33 2016 vermeu_v
** Last update Sun Mar 27 22:36:29 2016 vermeu_v
*/

#ifndef			CONVERT_H_
# define		CONVERT_H_

#include		"op.h"

typedef struct		s_instruct
{
  char			**pars_line;
  struct s_instruct	*next;
}			t_instruct;

typedef struct		s_wrt_lbl
{
  char			*label_name;
  t_instruct		*instruct;
  struct s_wrt_lbl	*next;
}			t_wrt_lbl;

char                    *get_next_line(const int fd);

# ifndef                READ_SIZE
#  define               READ_SIZE (10)
# endif                 /* READ_SIZE */

void			convert(int);
void			add_elem(t_wrt_lbl **, char *);
void			add_instruct(t_instruct **, char **);
void			take_instruct(t_wrt_lbl **, char **);

int			check_header(char **, t_header *);
int			check_def_label(t_wrt_lbl **, char *);

char			**my_tabcpy(char **);
char			**remove_label(char **);
char			*in_header(char *, char *);

#endif			/* !CONVERT_H_ */
