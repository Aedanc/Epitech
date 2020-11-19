/*
** my_epur_input for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon May 09 16:19:01 2016 Forteville Gabriel
** Last update Fri May 13 11:32:29 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include 	"minishell.h"

char		*clean_input(char *tmp, bool ismalloc)
{
  char			*tmp2;

  if (ismalloc == TRUE)
    tmp2 = my_epurstr(tmp, ';', TRUE);
  else
    tmp2 = my_epurstr(tmp, ';', FALSE);
  tmp2 = no_tab(tmp2);
  tmp2 = my_epurstr(tmp2, '|', TRUE);
  tmp2 = my_epurstr(tmp2, ' ', TRUE);
  return (tmp2);
}

char		**clean_all_input(char **input, bool ismalloc)
{
  int		index;

  index = 0;
  if (input == NULL)
    return (NULL);
  while (input[index] != NULL)
    {
      input[index] = clean_input(input[index], ismalloc);
      index++;
    }
  return (input);
}
