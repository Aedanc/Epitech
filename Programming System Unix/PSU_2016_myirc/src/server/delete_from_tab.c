/*
** delete_from_tab.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 19:58:20 2017 Pauline Maes
** Last update Sun Jun 11 20:02:39 2017 Pauline Maes
*/

#include	<stdlib.h>
#include	<string.h>
#include	"delete_from_tab.h"

char		**delete_from_tab(char *str, char **tab)
{
  int		i;
  int		j;
  int		len;
  char		**ret;

  i = 0;
  j = 0;
  len = 0;
  while (tab && tab[len])
    len++;
  if ((ret = malloc(sizeof(char *) * (len))) == NULL)
    return (NULL);
  while (tab && tab[i])
    {
      if (strcmp(str, tab[i]) != 0)
	{
	  ret[j] = strdup(tab[i]);
	  j++;
	}
      i++;
    }
  ret[i] = NULL;
  free_tab(tab);
  return (ret);
}
