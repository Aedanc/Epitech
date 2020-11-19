/*
** free_tab.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue May 03 18:45:57 2016 Forteville Gabriel
** Last update Tue May 03 18:46:44 2016 Forteville Gabriel
*/

#include 	<stdlib.h>
#include	"minishell.h"

void		free_tab(char **userinput)
{
  int		tab;

  tab = 0;
  if (userinput == NULL)
    return ;
  while (userinput[tab] != NULL)
    {
      free(userinput[tab]);
      tab++;
    }
  free(userinput);
}
