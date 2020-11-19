/*
** doshell.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan  4 18:41:47 2016 Forteville Gabriel
** Last update Fri May 13 16:03:35 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/wait.h>
#include		"minishell.h"

int			findpath(char **env)
{
  int			i;
  int			check;

  i = 0;
  if (env == NULL)
    return (0);
  while (env[i + 1] != NULL && (check = my_strcompare("PATH=", env[i], 5) != 5))
    i++;
  if (env[i + 1] == NULL)
    return (0);
  if (my_strlen(env[i]) <= 5)
    return (0);
  else
    return (i);
}

static void			check_error(int status)
{
  if (WTERMSIG(status) == 11)
    return ;
  if (WTERMSIG(status) == 8)
    return ;
}

int			try_to_exe(char **input, int i, char **env,
				   unsigned char result)
{
  char			**envclean;
  char			*tmp;

  tmp = NULL;
  if (env != NULL)
    tmp = my_strcpy(env[findpath(env)], 5, 0);
  envclean = my_str_to_word_tab(tmp, ':');
  free(tmp);
  if ((i = fork()) != 0)
    wait(&i);
  else
    {
      if ((input != NULL && input[0] != NULL) && (input[0][0] == '/'
	   || input[0][0] == '.'))
	exit(result = execve(input[0], input, env));
      result = 255;
      while (input != NULL && envclean != NULL && envclean[i] != NULL)
	{
	  result = execve(tmp = (my_path(envclean[i++], input[0])), input, env);
	  free(tmp);
	}
      exit (result);
    }
  free_tab(envclean);
  return (i);
}

char			**doshell(char **input, char **env, char **need_free)
{
  int			i;

  i = 0;
  if (my_strcompare("env", input[0], 60) == 3)
    my_env(env);
  else if (my_strcompare("setenv", input[0], 6) == 6)
    env = my_setenv(input, env);
  else if (my_strcompare("cd", input[0], 3) == 2)
    env = my_cd(input, env);
  else if (my_strcompare("unsetenv", input[0], 9) == 8)
    env = my_unsetenv(input, env);
  else if (my_strcompare("exit", input[0], 5) == 4)
    my_exit(input, env, need_free);
  else if ((i = try_to_exe(input, 0, env, 255)) == 65280)
    {
      i = 0;
      while (input != NULL && input[0] != NULL &&
	     input[0][i++] != ' ' && input[0][i] != 0);
      write(2, input[0], i);
      write(2, ": Command not found.\n", 21);
    }
  if (WIFSIGNALED(i) == TRUE)
        check_error(i);
  return (env);
}
