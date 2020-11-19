/*
** main.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan  4 10:07:15 2016 Forteville Gabriel
** Last update Fri May 13 16:06:50 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		<signal.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		"minishell.h"

static void		don_t_stop_me_now(int sig)
{
  if (sig == 2 || sig == 20)
    my_putstr("\n$>");
  else if (sig == 3)
    {
      my_putstr("exit\n");
      exit (0);
    }
}

static bool 		pipe_is_ok(char *input, int index)
{
  bool			is_ok;

  is_ok = TRUE;
  while (input[index] != 0 && is_ok == TRUE)
    {
      index++;
      if (input[index] == ';' || input[index] == '|')
	return (FALSE);
      if (input[index] != ' ')
	is_ok = FALSE;
    }
  return (TRUE);
}

static int	check_error_pipe(char *input)
{
  int		index;
  int		return_value;
  char		*tmp;

  return_value = FALSE;
  index = 0;
  while (input[index] != 0)
    {
      if (input[0] == '|' || (input[index] == '|'
      && pipe_is_ok(input, index) == FALSE))
	return (my_puterror("Invalid null command.\n"));
      if (input[index] == '|')
	return_value = TRUE;
      index++;
    }
  tmp = clean_input(input, FALSE);
  if (tmp[0] == '|')
    return (my_puterror("Invalid null command.\n"));
  free (tmp);
  return (return_value);
}

char		**condition(char **env, char tmp[4096], int i)
{
  char		**one_command;
  char		**userinput;
  char		*for_free;

  if (check_error_pipe(tmp) == -1)
    return (env);
  userinput = my_str_to_word_tab(for_free = clean_input(tmp, FALSE), ';');
  free(for_free);
  while (userinput[i] != NULL)
    {
      if (check_error_pipe(userinput[i]) == TRUE)
	env = multi_pipe(userinput[i], env);
      else
	{
	  one_command = my_str_to_word_tab(userinput[i], ' ');
	  env = doshell(one_command, env, userinput);
	  free_tab(one_command);
	}
      if (userinput[i] != NULL)
	i++;
    }
  free_tab(userinput);
  return (env);
}

int		main(int ac, char **av, char **env)
{
  char	        tmp[4096];
  int		i;
  int		istty;
  struct stat	sb;
  char		**new_env;

  fstat(0, &sb);
  istty = (S_ISCHR(sb.st_mode)) ? 0 : 1;
  (void)ac;
  (void)av;
  new_env = remalloc_env(env, FALSE);
  while (1)
    {
      signal(SIGTSTP, don_t_stop_me_now);
      signal(SIGINT, don_t_stop_me_now);
      if (istty == 0)
	my_putstr("$>");
      i = read(0, tmp, 4096);
      if (i == 0)
	my_exit(NULL, NULL, NULL);
      tmp[i - 1] = 0;
      new_env = condition(new_env, tmp, 0);
    }
  free_tab(new_env);
  return (0);
}
