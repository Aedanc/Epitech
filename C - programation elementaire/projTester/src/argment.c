/*
** aphabe_tree.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 23 12:55:31 2016 Forteville Gabriel
** Last update Sat Jun 25 09:19:56 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<string.h>
#include	<string.h>
#include	"basic.h"
#include	"src.h"
#include	"arguments.h"

static int	end_file(char *str, char *end_of_file)
{
  int		i;
  int		cmp;

  i = my_strlen(str) - my_strlen(end_of_file);
  if (i < 0)
   return (0);
  cmp = 0;
  while (str[i] != 0)
    {
      if (str[i] != end_of_file[cmp])
	return (0);
      cmp++;
      i++;
    }
  return (1);
}

static int	alpha_order(const void *p1, const void *p2)
{
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static char	**add_tab(char name[256], char **tab)
{
  int		index;

  index = 0;
  while (tab[index] != NULL)
    index++;
  if ((tab = realloc(tab, (sizeof(char *) * (index + 2)))) == NULL)
    error("fail malloc");
  tab[index + 1] = NULL;
  tab[index] = strdup(name);
  return (tab);
}

void		argment(char *name_dir, DIR *dir, char *command)
{
  struct dirent	*ent;
  char		**tab;
  int		index;

  if ((tab = malloc(sizeof(char *) * 1)) == NULL)
    return ;
  tab[0] = NULL;
  while ((ent = readdir(dir)) != NULL)
    if (ent->d_name[0] != '.')
      tab = add_tab(ent->d_name, tab);
  closedir(dir);
  qsort(&tab[0], tablen(tab), sizeof(char *), alpha_order);
  index = -1;
  while (tab[++index] != NULL)
    if (chdir(tab[index]) == 0)
      argment(name_dir, opendir("."), command);
    else if (end_file(tab[index], ".tdf") == 1)
      execute(name_dir, tab[index], command);
  chdir("..");
  freetab(tab);
}
