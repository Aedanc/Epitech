/*
** my_free_tab_tab_int.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue May 10 17:25:10 2016 Forteville Gabriel
** Last update Tue May 10 17:31:05 2016 Forteville Gabriel
*/

#include	<stdlib.h>

void		my_free_tab_tab_int(int **tab_tab_int)
{
  int		index;

  index = 0;
  while (tab_tab_int[index] != NULL)
    {
      free(tab_tab_int[index]);
      index++;
    }
  free(tab_tab_int);
}
