/*
** free_tab.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 19:41:14 2017 Pauline Maes
** Last update Sun Jun 11 19:42:02 2017 Pauline Maes
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab && tab[i])
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
