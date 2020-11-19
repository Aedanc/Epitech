/*
** add_instruct.c for add_instruct in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri Mar 25 04:21:38 2016 Hugo Baldassin
** Last update Sun Mar 27 08:29:46 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"
#include	"convert.h"

void		add_instruct(t_instruct **instruct_list, char **pars_line)
{
  t_instruct	*elem;
  t_instruct	*tmp;

  tmp = (*instruct_list);
  if (!(elem = malloc(sizeof(t_instruct))))
    error_displays(-7, 0);
  elem->pars_line = my_tabcpy(pars_line);
  if ((*instruct_list) != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->next = NULL;
    }
  else
    {
      (*instruct_list) = elem;
      elem->next = NULL;
    }
}
