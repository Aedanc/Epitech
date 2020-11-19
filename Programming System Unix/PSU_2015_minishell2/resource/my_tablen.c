/*
** len_tab.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Apr 26 00:11:03 2016 Forteville Gabriel
** Last update Tue Apr 26 00:58:41 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		my_tablen(char **tab)
{
  int		len;

  len = 0;
  while (tab[len] != NULL)
    len++;
  return (len);
}
