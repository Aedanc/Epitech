/*
** remove_label.c for remove_label in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sun Mar 27 21:05:02 2016 vermeu_v
** Last update Sun Mar 27 23:13:51 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"my.h"

char		**remove_label(char **line_pars)
{
  int		cpt;
  int		nbr_param;
  char		**new_line;

  cpt = 0;
  nbr_param = 0;
  while (line_pars[nbr_param] != NULL)
    nbr_param++;
  if ((new_line = malloc(sizeof(char *) * nbr_param)) == NULL)
    return (NULL);
  new_line[nbr_param - 1] = NULL;
  while (cpt < nbr_param - 1)
    {
      new_line[cpt] = my_strcpy(line_pars[cpt + 1]);
      cpt++;
    }
  return (new_line);
}
