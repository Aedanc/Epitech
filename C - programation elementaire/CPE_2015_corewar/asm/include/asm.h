/*
** asm.h for asm in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/baldas/include
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Wed Mar 16 12:38:49 2016 Hugo Baldassin
** Last update Thu Mar 24 23:22:49 2016 Hugo Baldassin
*/

#ifndef		ASM_H_
# define	ASM_H_

/*
** Label_struct
*/

typedef struct		s_label
{
  char			*label;
  int			check;
  int			line;
  struct s_label	*next;
}			t_label;

/*
** Divers
*/

int			args_errors(int ac, char **av);

void			fake_printf(char *p1, int nb, char *str, char *p2);

void			error_displays(int flag, int y);

char			*epur_label(char *arg);

void			file_errors_display(int flag, char *name);

long			power_of_two(int n);

long			my_get_long(char *str);

/*
** Parsing
 */

int			compile_and_pars(char *name);

char			**my_cmd_tab(char *line);

char			*epur_line(char *line);

void			epur_tab(char **tab);

int			is_a_register(char *arg, int y);

int			is_a_label(char *arg, int y);

int			is_a_label_char(char c);

int			is_a_direct(char *arg, int y);

int			is_an_index(char *arg, int y);

int			is_num(char *str);

int			is_a_command(char *arg);

int			what_type_is_it(char *arg, int y);

void			check_cmd(char **cmd_tab, t_label **label_list, int y);

void			check_param(char **arg, int y);

int			first_word_label(char *line);

void			add_label(char *arg, t_label **label_list, int y);

int			check_label_list(char *arg, t_label *label_list);

void			final_list_check(t_label *label_list);

#endif			/* ASM_H_ */
