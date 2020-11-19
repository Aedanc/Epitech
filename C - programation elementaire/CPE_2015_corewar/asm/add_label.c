/*
** add_label.c for add_label in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Mar 21 19:06:00 2016 Hugo Baldassin
** Last update Thu Mar 24 18:03:50 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"my.h"

char		*epur_label(char *arg)
{
  int		i;
  int		j;
  char		*label;

  if (arg[0] == DIRECT_CHAR)
    if (!(label = malloc((my_strlen(arg) - 1) * sizeof(char))))
      error_displays(-7, 0);
  if (arg[0] != DIRECT_CHAR)
    if (!(label = malloc(my_strlen(arg) * sizeof(char))))
      error_displays(-7, 0);
  i = (arg[0] == DIRECT_CHAR) ? 2 : 0;
  j = 0;
  while (arg[i] != '\0' && arg[i] != LABEL_CHAR)
    {
      label[j] = arg[i];
      i++;
      j++;
    }
  label[j] = '\0';
  return (label);
}

void		add_label(char *arg, t_label **label_list, int y)
{
  t_label	*elem;
  t_label	*tmp;

  if (check_label_list(arg, (*label_list)) == 1)
    return ;
  tmp = (*label_list);
  if (!(elem = malloc(sizeof(t_label))))
    error_displays(-7, 0);
  elem->label = epur_label(arg);
  elem->check = (arg[0] == DIRECT_CHAR) ? 0 : 1;
  elem->line = y;
  if ((*label_list) != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->next = NULL;
    }
  else
    {
      (*label_list) = elem;
      elem->next = NULL;
    }
}
