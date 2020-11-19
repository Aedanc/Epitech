/*
** freechamp.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Mar 26 10:41:48 2016 Forteville Gabriel
** Last update Sun Mar 27 16:04:20 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"op.h"

void		freechamp(t_champions *champafree,
			  t_champions **allchamp)
{
  t_champions	*tmpchamp;
  t_process	*processafree;

  tmpchamp = (*allchamp);
  if (tmpchamp == NULL || tmpchamp->next == NULL)
    return ;
  while (tmpchamp->next != NULL && tmpchamp->ch_nb != champafree->ch_nb)
    tmpchamp = tmpchamp->next;
  tmpchamp = tmpchamp->next;
  free(champafree->header);
  free(champafree->bytecode);
  while (champafree->process->next != NULL)
    {
      processafree = champafree->process;
      while (processafree->next != NULL)
	processafree = processafree->next;
      free(processafree);
    }
}
