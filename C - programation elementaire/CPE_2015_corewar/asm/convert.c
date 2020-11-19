/*
** convert.c for convert in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/vermeu/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Mon Mar 21 18:28:02 2016 vermeu_v
** Last update Sun Mar 27 22:57:31 2016 vermeu_v
*/

#include	<stdlib.h>
#include 	"op.h"
#include	"my.h"
#include	"asm.h"
#include	"convert.h"

void		convert(int fd)
{
  int		check;
  char		*line;
  char		**line_pars;
  t_wrt_lbl	*label;
  t_header	header;

  while ((line = get_next_line(fd)) != NULL)
    {
      line = epur_line(line);
      line_pars = my_cmd_tab(line);
      if (line_pars[0] != NULL && check_header(line_pars, &header) != 1)
	{
	  if ((check = check_def_label(&label, line_pars[0])) == 1 &&
	      line_pars[1] != NULL)
	    {
	      add_elem(&label, line_pars[0]);
	      remove_label(line_pars);
	      take_instruct(&label, line_pars);
	    }
	  else
	    take_instruct(&label, line_pars);
	}
    }
}
