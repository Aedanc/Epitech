/*
** in_tab.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 19:42:32 2017 Pauline Maes
** Last update Sun Jun 11 19:43:26 2017 Pauline Maes
*/

#include	<string.h>

int		in_tab(char *str, char **tab)
{
  int		i;

  i = 0;
  while (tab && tab[i])
    {
      if (strcmp(str, tab[i]) == 0)
	return (1);
      i++;
    }
  return (0);
}
