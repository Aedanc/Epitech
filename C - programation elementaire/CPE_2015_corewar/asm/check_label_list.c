/*
** check_label_list.c for check_label_list in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Mar 21 17:38:14 2016 Hugo Baldassin
** Last update Thu Mar 24 18:55:57 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"
#include	"op.h"

int		check_label_list(char *arg, t_label *label_list)
{
  char		*label;
  int		check;
  t_label	*tmp;

  tmp = label_list;
  check = (arg[0] == DIRECT_CHAR) ? 0 : 1;
  label = epur_label(arg);
  while (tmp != NULL)
    {
      if (my_strcmp(label, tmp->label) == 0)
	{
	  if (check == 1)
	    tmp->check = 1;
	  free(label);
	  return (1);
	}
      tmp = tmp->next;
    }
  free(label);
  return (0);
}
