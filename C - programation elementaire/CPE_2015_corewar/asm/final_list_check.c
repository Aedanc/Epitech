/*
** final_list_check.c for final_list_check in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Mar 24 18:00:51 2016 Hugo Baldassin
** Last update Thu Mar 24 18:56:43 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"

void		free_list(t_label *label_list)
{
  t_label	*tmp;

  while (label_list != NULL)
    {
      tmp = label_list;
      label_list = label_list->next;
      free(tmp->label);
      free(tmp);
    }
}

void		final_list_check(t_label *label_list)
{
  t_label	*tmp;

  tmp = label_list;
  while (tmp != NULL)
    {
      if (tmp->check != 1)
	{
	  fake_printf("label ", 0, tmp->label, " undefined");
	  fake_printf(" line ", tmp->line, NULL, "\n");
	  free_list(label_list);
	  exit(-3);
	}
      tmp = tmp->next;
    }
  free_list(label_list);
}
