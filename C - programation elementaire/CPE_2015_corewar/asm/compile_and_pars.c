/*
** compile_and_pars.c for compile_and_pars in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Mar 23 17:04:28 2016 Hugo Baldassin
** Last update Sat Mar 26 18:45:16 2016 Hugo Baldassin
*/

#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		"op.h"
#include		"asm.h"
#include		"get_next_line.h"
#include		"my.h"
#include		"convert.h"

void			pars_line(char *line, t_label **label_list, int y)
{
  char			**cmd_tab;
  char			*epur;

  epur = epur_line(line);
  cmd_tab = my_cmd_tab(epur);
  if (cmd_tab[0] != NULL && cmd_tab[0][0] != COMMENT_CHAR &&
      cmd_tab[0][0] != '\0')
    {
      if (is_a_label(cmd_tab[0], y) == 1)
	add_label(cmd_tab[0], label_list, y);
      if (cmd_tab[0][0] == '.')
	check_param(cmd_tab, y);
      else
	check_cmd(cmd_tab, label_list, y);
    }
  free(epur);
  free_tab(cmd_tab);
}

int			compile_and_pars(char *name)
{
  int			fd;
  int			y;
  t_label		*label_list;
  char			*line;

  y = 1;
  label_list = NULL;
  if ((fd = open(name, O_RDONLY)) == -1)
    file_errors_display(-6, name);
  while ((line = get_next_line(fd)) != NULL)
    {
      pars_line(line, &label_list, y);
      y++;
    }
  if (line == NULL && y == 1)
    file_errors_display(-8, name);
  final_list_check(label_list);
  lseek(fd, 0, SEEK_SET);
  convert(fd);
  if (close(fd) == -1)
    {
      file_errors_display(0, name);
      return (-1);
    }
  return (0);
}
