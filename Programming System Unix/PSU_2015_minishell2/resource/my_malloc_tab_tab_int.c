/*
** my_malloc_tab_tab_int.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue May 10 16:13:53 2016 Forteville Gabriel
** Last update Tue May 10 17:22:20 2016 Forteville Gabriel
*/

#include 	<stdlib.h>

int		**my_malloc_tab_tab_int(int len_tab_tab, int len_tab)
{
  int		**tab_tab_int;
  int		index;

  index = 0;
  if ((tab_tab_int = malloc(sizeof(int *) * (len_tab_tab + 1))) == NULL)
    return (NULL);
  while (index < len_tab_tab)
    {
      if ((tab_tab_int[index] = malloc(sizeof(int) * (len_tab))) == NULL)
	return (NULL);
      index++;
    }
  tab_tab_int[index] = NULL;
  return (tab_tab_int);
}
