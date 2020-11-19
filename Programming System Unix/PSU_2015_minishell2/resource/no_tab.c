/*
** no_tab for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed May 11 20:09:08 2016 Forteville Gabriel
** Last update Fri May 13 11:34:27 2016 Forteville Gabriel
*/

#include        <stdlib.h>
#include        "minishell.h"

char		*no_tab(char *str)
{
  int		index;

  index = 0;
  while (str[index] != 0)
    {
      if (str[index] == '\t')
	str[index] = ' ';
      index++;
   }
  return (str);
}
