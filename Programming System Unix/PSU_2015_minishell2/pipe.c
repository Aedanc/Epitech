/*
** pipe.c for minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue May  3 14:59:12 2016 Forteville Gabriel
** Last update Tue May 10 16:05:55 2016 Forteville Gabriel
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<sys/wait.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		"minishell.h"

static void		commande_not_found(char **commande)
{
  int		i;

  i = 0;
  while (commande[0][i++] != ' ' && commande[0][i] != 0);
  write(2, commande[0], i);
  write(2, ": Command not found.\n", 21);
}

static int			try_to_exe_for_pipe(char **input, int i,
						    char **env,
						    unsigned char result)
{
  char			**envclean;
  char			*tmp;

  tmp = NULL;
  if (env != NULL)
    tmp = my_strcpy(env[findpath(env)], 5, 0);
  if ((envclean = my_str_to_word_tab(tmp, ':')) == NULL)
    return (-2);
  if (input[0][0] == '/' || input[0][0] == '.')
    exit(result = execve(input[0], input, env));
  while (envclean != NULL && envclean[i] != NULL && result == 200)
    {
      result = execve(tmp = (my_path(envclean[i++], input[0])), input, env);
      free(tmp);
    }
  free_tab(envclean);
  return (WEXITSTATUS(i));
}

static int		execute(int pos, int pipefd[2], char **env,
				char **commande)
{
  int		result;

  close(pipefd[pos]);
  if (pos == 0)
    dup2(pipefd[1], 1);
  else
    dup2(pipefd[0], 0);
  result = try_to_exe_for_pipe(commande, 0, env, 255);
  if (result == 255)
    commande_not_found(commande);
  exit (result);
}

static char		**schedul_pipe(char **commande1, char **commande2,
				       char **env)
{
  int		pipefd[2];
  int		result;

  result = -1;
  if (pipe(pipefd) == result)
    exit (-1);
  if (fork() == 0)
    {
      if (fork() == 0)
	execute(0, pipefd, env, commande1);
      else
	execute(1, pipefd, env, commande2);
      exit(0);
    }
  else
    {
      close(pipefd[0]);
      close(pipefd[1]);
      wait(&result);
    }
  return (env);
}

char		**do_pipe(char *input, char **env)
{
  char		**tmp;
  char		**commande1;
  char		**commande2;

  if (input == NULL)
    return (env);
  tmp = my_str_to_word_tab(input, '|');
  commande1 = my_str_to_word_tab(clean_input(tmp[0], TRUE), ' ');
  commande2 = my_str_to_word_tab(clean_input(tmp[1], TRUE), ' ');
  env = schedul_pipe(commande1, commande2, env);
  free_tab(tmp);
  free_tab(commande1);
  free_tab(commande2);
  return (env);
}
