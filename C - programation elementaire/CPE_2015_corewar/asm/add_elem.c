/*
** add_elem.c for add_elem in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sat Mar 26 18:55:10 2016 Hugo Baldassin
** Last update Sun Mar 27 07:17:56 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"convert.h"
#include	"asm.h"
#include	"my.h"

void		add_elem(t_wrt_lbl **wrt_list, char *label)
{
  t_wrt_lbl	*elem;
  t_wrt_lbl	*tmp;

  tmp = (*wrt_list);
  if (!(elem = malloc(sizeof(t_wrt_lbl))))
    error_displays(-7, 0);
  elem->label_name = my_strcpy(label);
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->next = NULL;
    }
  else
    {
      (*wrt_list) = elem;
      elem->next = NULL;
    }
}
