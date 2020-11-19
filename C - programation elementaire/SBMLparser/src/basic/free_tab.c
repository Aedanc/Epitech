/*
** free_tab.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jun 13 16:49:48 2016 Forteville Gabriel
** Last update Mon Jun 13 16:55:27 2016 Forteville Gabriel
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    {
      free(tab[cpt]);
      cpt++;
    }
  free(tab);
}
