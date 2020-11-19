/*
** my_setenv.c for PSU_2015_minishell1 in /home/fortevg/rendu/PSU/PSU_2015_minishell1/Builtins
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Apr 06 17:03:16 2016 Forteville Gabriel
** Last update Wed May 11 16:24:17 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

int		checkname(char *name)
{
  int		i;

  i = 0;
  while (name[i] != 0)
    {
      if ((name[i] < 'a' && name[i] > 'z') ||
	  (name[i] < 'A' && name[i] > 'Z') ||
	  (name[i] < '0' && name[i] > '9'))
	return (my_putstr("setenv: Variable name"
			 "must contain alphanumeric characters."));
	i++;
    }
  return (0);
}

char		**my_setenv(char **value,
			    char **env)
{
  int		i;

  i = 0;
  if (value[1] == NULL)
    {
      my_env(env);
      return (env);
    }
  if (checkname(value[1]) != 0)
    return (env);
  while (env != NULL && (env[i] != NULL && my_strcompare
	 (value[1], env[i], my_strlen(value[1])) != my_strlen(value[1])))
    i++;
  if (env == NULL || env[i] == NULL)
    {
      env = remalloc_env(env, TRUE);
      env[i] = my_newvarenv(my_strcpy(value[1], 0, 0), my_strcpy(value[2], 0, 0)
			    , TRUE, TRUE);
      env[i + 1] = NULL;
    }
  else
    free(env[i]);
  env[i] = my_newvarenv(my_strcpy(value[1], 0, 0), my_strcpy(value[2], 0, 0)
			, TRUE, TRUE);
  return (env);
}
