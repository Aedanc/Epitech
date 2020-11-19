/*
** check_def_label.c for check_def_label in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/baldas/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Fri Mar 25 04:23:05 2016 vermeu_v
** Last update Sun Mar 27 23:13:58 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"convert.h"

int		check_def_label(t_wrt_lbl **label, char *str)
{
  int		cpt;

  cpt = 0;
  if (((*label) = malloc(sizeof(t_wrt_lbl))) == NULL)
    return(2);
  (*label)->next = NULL;
  while (str[cpt] != 0)
    {
      if (str[cpt] == ':' && str[cpt + 1] == 0)
	{
	  add_elem(label, str);
	  return (1);
	}
      cpt++;
    }
  return (0);
}
