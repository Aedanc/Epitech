/*
** my_unsetenv.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/Builtins
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Apr 25 23:30:41 2016 Forteville Gabriel
** Last update Fri May 13 14:55:30 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

static char		**delete_var_env(char **env,
					 int index)
{
  while (env[index + 1] != NULL)
    {
      free(env[index]);
      env[index] = my_strcpy(env[index + 1], 0, 0);
      index++;
    }
  free(env[index]);
  env[index] = NULL;
  return (env);
}

char		**my_unsetenv(char **input,
			      char **env)
{
  int		index;
  int		name_var_env_len;

  if (env != NULL)
    {
      index = 0;
      if (input[1] != NULL)
	{
	  while (env[index] != NULL)
	    {
	      name_var_env_len = 0;
	      while (env[index][name_var_env_len + 1] != '=')
		  name_var_env_len++;
	      if (my_strcompare(input[1], env[index], name_var_env_len) != -1)
		env = delete_var_env(env, index);
	      index++;
	    }
	}
      else
	my_puterror("unsetenv: Too few arguments.\n");
  }
  return (env);
}
