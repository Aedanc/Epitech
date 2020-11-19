/*
** check_param.c for check_param in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sun Mar 20 20:38:29 2016 Hugo Baldassin
** Last update Fri Mar 25 00:36:38 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"my.h"
#include	"asm.h"
#include	"op.h"

int		is_a_param(char *arg)
{
  if (my_strcmp(arg, NAME_CMD_STRING) != 0 &&
      my_strcmp(arg, COMMENT_CMD_STRING) != 0 &&
      my_strcmp(arg, ".code") != 0)
    return (0);
  return (1);
}

void		check_param(char **cmd_tab, int y)
{
  int		tablen;
  static int	name = 0;
  static int	comment = 0;

  tablen = my_tablen(cmd_tab);
  if (my_strcmp(cmd_tab[0], ".extend") == 0 && tablen == 1)
      return ;
  if (is_a_param(cmd_tab[0]) == 0 || tablen <= 1)
    error_displays(-1, y);
  else if (my_strlen(cmd_tab[1]) <= 2)
    error_displays(-1, y);
  else if (cmd_tab[1][0] != '\"' ||
	   cmd_tab[tablen - 1][my_strlen(cmd_tab[tablen - 1]) - 1] != '\"')
    error_displays(-1, y);
  if (my_strcmp(cmd_tab[0], NAME_CMD_STRING) == 0)
    name++;
  if (my_strcmp(cmd_tab[0], COMMENT_CMD_STRING) == 0)
    comment++;
  if (name > 1 || comment > 2)
    error_displays(-9, y);
}
