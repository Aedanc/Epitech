/*
** remalloc_env.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Apr 18 16:14:30 2016 Forteville Gabriel
** Last update Wed May 11 17:45:46 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

static int		malloc_new_env(char ***new_env,
				       char **env,
				       bool check)
{
  int		nbrtab;
  int		i;

  nbrtab = 0;
  while (env != NULL && env[nbrtab] != NULL)
    nbrtab++;
  if (check == TRUE)
    {
      if (((*new_env) = malloc(sizeof(char *) * (nbrtab + 2))) == NULL)
	exit (-1);
      (*new_env)[nbrtab + 1] = NULL;
    }
  else
    if (((*new_env) = malloc(sizeof(char *) * (nbrtab + 1))) == NULL)
      exit (-1);
  (*new_env)[nbrtab] = NULL;
  i = 0;
  while (i < nbrtab)
    {
      if (((*new_env)[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) ==
	  NULL)
	exit (-1);
      i++;
    }
  return (i);
}

static void		copy_new_env(char ***new_env, char **env, int sizetab)
{
  int			nbrtab;
  int			i;

  nbrtab = 0;
  while (nbrtab < sizetab)
    {
      i = 0;
      while (env[nbrtab][i] != 0)
	{
	  (*new_env)[nbrtab][i] = env[nbrtab][i];
	  i++;
	}
      (*new_env)[nbrtab][i] = 0;
      nbrtab++;
    }
}

char		**remalloc_env(char **env, bool check)
{
  char		**new_env;
  int		i;

  new_env = NULL;
  if (env != NULL)
    {
      i = malloc_new_env(&new_env, env, check);
      copy_new_env(&new_env, env, i);
      if (check == TRUE)
	free_tab(env);
    }
  return (new_env);
}
