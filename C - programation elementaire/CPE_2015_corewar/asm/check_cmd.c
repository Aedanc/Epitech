/*
** check_cmd.c for check_cmd in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sun Mar 20 20:47:42 2016 Hugo Baldassin
** Last update Thu Mar 24 22:49:38 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"my.h"

void		check_validity(char **cmd_tab, t_label **label_list, int i, int y)
{
  int		j;
  int		k;
  int		c;
  int		type;

  j = is_a_label(cmd_tab[0], y);
  k = j + 1;
  if ((my_tablen(cmd_tab) - 1 - j) != op_tab[i].nbr_args)
    error_displays(-1, y);
  j += 1;
  while (cmd_tab[j] != NULL)
    {
      type = what_type_is_it(cmd_tab[j], y);
      c = type & op_tab[i].type[j - k];
      if (type != c)
	error_displays(-1, y);
      if (c == 2 && is_a_label(cmd_tab[j], y) == 1)
	add_label(cmd_tab[j], label_list, y);
      j++;
    }
}

void		check_cmd(char **cmd_tab, t_label **label_list, int y)
{
  int		j;
  int		i;

  j = (is_a_label(cmd_tab[0], y) == 1) ? 1 : 0;
  if (j == 1 && cmd_tab[1] == NULL)
    return ;
  i = is_a_command(cmd_tab[j]);
  if (i == -1)
    error_displays(-1, y);
  check_validity(cmd_tab, label_list, i, y);
}
