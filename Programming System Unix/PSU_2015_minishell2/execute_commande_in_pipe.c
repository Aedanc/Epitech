/*
** execute_commande_in_pipe.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed May 11 09:25:07 2016 Forteville Gabriel
** Last update Fri May 13 15:30:19 2016 Forteville Gabriel
*/

#include			<stdlib.h>
#include			<unistd.h>
#include			"minishell.h"

bool			is_builting(char **input,
				    char **env)
{
  if (input == NULL)
    return (FALSE);
  if (my_strcompare("env", input[0], 60) == 3)
    {
      my_env(env);
      return (TRUE);
    }
  else if (my_strcompare("setenv", input[0], 6) == 6)
    {
      env = my_setenv(input, env);
      return (TRUE);
    }
  else if (my_strcompare("cd", input[0], 3) == 2 ||
	   my_strcompare("unsetenv", input[0], 9) == 8 ||
  	   my_strcompare("exit", input[0], 5) == 4)
    return (TRUE);
  return (FALSE);
}

static int			try_to_exe_for_pipe(char **input,
						    int i,
						    char **env,
						    unsigned char result)
{
  char			**envclean;
  char			*tmp;

  tmp = NULL;
  if (env != NULL)
    tmp = my_strcpy(env[findpath(env)], 5, 0);
  if (input[0][0] == '/' || input[0][0] == '.')
    exit(execve(input[0], input, env));
  if ((envclean = my_str_to_word_tab(tmp, ':')) == NULL)
    {
      my_puterror(input[0]);
      exit(my_puterror(": command not found\n"));
    }
  while (envclean != NULL && envclean[i] != NULL && result == 255)
    {
      result = execve(tmp = (my_path(envclean[i++], input[0])), input, env);
      free(tmp);
    }
  if (envclean[i] == NULL)
    {
      my_puterror(input[0]);
      exit(my_puterror(": command not found\n"));
    }
  free_tab(envclean);
  exit (result);
}

void		first_command(int **tab_pipe_fd,
			      char *command,
			      char **env)
{
  bool		need_close[2];
  char		**command_exe;

  need_close[0] = TRUE;
  need_close[1] = FALSE;
  dup2(tab_pipe_fd[0][1], 1);
  tab_pipe_fd = close_tab_pipe(tab_pipe_fd, 0, need_close);
  command_exe = my_str_to_word_tab(command, ' ');
  if (is_builting(command_exe, env) == FALSE)
    try_to_exe_for_pipe(command_exe, 0, env, 255);
  exit (0);
}

void		mid_command(int **tab_pipe_fd,
			    int index,
			    char *command,
			    char **env)
{
  bool		need_close[2];
  char		**command_exe;

  need_close[0] = TRUE;
  need_close[1] = FALSE;
  dup2(tab_pipe_fd[index - 1][0], 0);
  dup2(tab_pipe_fd[index][1], 1);
  tab_pipe_fd = close_tab_pipe(tab_pipe_fd, index, need_close);
  command_exe = my_str_to_word_tab(command, ' ');
  if (is_builting(command_exe, env) == FALSE)
      try_to_exe_for_pipe(command_exe, 0, env, 255);
  exit (0);
}

void		last_command(int **tab_pipe_fd,
			     int index,
			     char *command,
			     char **env)
{
  bool		need_close[2];
  char		**command_exe;

  need_close[0] = TRUE;
  need_close[1] = TRUE;
  dup2(tab_pipe_fd[index - 1][0], 0);
  dup2(1, tab_pipe_fd[index - 1][1]);
  tab_pipe_fd = close_tab_pipe(tab_pipe_fd, index, need_close);
  command_exe = my_str_to_word_tab(command, ' ');
  if (is_builting(command_exe, env) == FALSE)
    try_to_exe_for_pipe(command_exe, 0, env, 255);
}
