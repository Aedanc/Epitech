/*
** aphabe_tree.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 23 12:55:31 2016 Forteville Gabriel
** Last update Fri Jun 24 22:44:09 2016 Gabriel Forteville
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<string.h>
#include	"basic.h"
#include	"src.h"

static int alpha_order(const void *p1, const void *p2)
{
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static int	my_chdir(char *str)
{
  char		*path;
  int		index;
  int		tmp;

  tmp = 0;
  index = 0;
  while (str[index] != 0 && str[index] == '-')
    index++;
  if ((path = malloc(sizeof(char) * (strlen(str) - index + 1))) == NULL)
    error("malloc fail");
  while (str[index] != 0)
    {
      path[tmp] = str[index];
      tmp++;
      index++;
    }
  path[tmp] = 0;
  tmp = chdir(path);
  free(path);
  return (tmp);
}

static char	**add_tab(char name[256], int nbr_stack, char **tab)
{
  int		tmp;
  int		index;

  index = 0;
  while (tab[index] != NULL)
    index++;
  if ((tab = realloc(tab, (sizeof(char *) * (index + 2)))) == NULL)
    error("fail malloc");
  tab[index + 1] = NULL;
  tmp = 0;
  if ((tab[index] = malloc(sizeof(char) * (nbr_stack * 5 + strlen(name) + 1)))
       == NULL)
    error("fail malloc");
  while (tmp <= nbr_stack * 5)
    {
      tab[index][tmp] = '-';
      tmp++;
    }
  tab[index][tmp - 1] = 0;
  tab[index] = strcat(tab[index], name);
  tab[index][nbr_stack * 5 + strlen(name)] = 0;
  return (tab);
}

void		alphabe_tree(DIR *dir, int nbr_stack)
{
  struct dirent	*ent;
  char		**tab;
  int		index;

  if ((tab = malloc(sizeof(char *) * 1)) == NULL)
    return ;
  tab[0] = NULL;
  while ((ent = readdir(dir)) != NULL)
    if (ent->d_name[(index = 0)] != '.')
      tab = add_tab(ent->d_name, nbr_stack, tab);
  closedir(dir);
  qsort(&tab[0], tablen(tab), sizeof(char *), alpha_order);
  while (tab[index] != NULL)
    {
      if (my_chdir(tab[index]) == 0)
	{
	  printf("%s/\n", tab[index]);
	  alphabe_tree(opendir("."), nbr_stack + 1);
	  chdir("..");
	}
      else
	printf("%s\n", tab[index]);
      index++;
    }
  freetab(tab);
}
