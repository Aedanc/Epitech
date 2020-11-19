/*
** take_instruct.c for take_instruct in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sun Mar 27 08:35:46 2016 vermeu_v
** Last update Sun Mar 27 23:13:41 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"convert.h"
#include	"my.h"

void		take_instruct(t_wrt_lbl **label, char **line_pars)
{
  int		cpt;
  int		nbr_param;

  cpt = 0;
  nbr_param = 0;
  while (line_pars[nbr_param] != NULL)
    nbr_param++;
  if (((*label)->instruct = malloc(sizeof(t_instruct))) == NULL)
    return;
  if (((*label)->instruct->pars_line =
       malloc(sizeof(char *) * nbr_param + 1)) == NULL)
    return;
  (*label)->instruct->pars_line[nbr_param] = NULL;
  while (cpt < nbr_param - 1)
    {
      (*label)->instruct->pars_line[cpt] = my_strcpy(line_pars[cpt]);
      cpt ++;
    }
}
