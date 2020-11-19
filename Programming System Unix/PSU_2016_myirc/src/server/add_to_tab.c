/*
** add_to_tab.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 19:37:43 2017 Pauline Maes
** Last update Sun Jun 11 19:41:11 2017 Pauline Maes
*/

#include	<stdlib.h>
#include	<string.h>
#include	"add_to_tab.h"

char		**add_to_tab(char *str, char **tab)
{
  int		i;
  int		len;
  char		**ret;

  i = 0;
  len = 0;
  while (tab && tab[len])
    len++;
  if ((ret = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  while (tab && tab[i])
    {
      ret[i] = strdup(tab[i]);
      i++;
    }
  ret[i] = strdup(str);
  ret[i + 1] = NULL;
  free_tab(tab);
  return (NULL);
}
