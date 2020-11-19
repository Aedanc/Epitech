/*
** multi_pipe.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon May 09 21:22:11 2016 Forteville Gabriel
** Last update Fri May 13 14:49:40 2016 Forteville Gabriel
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<sys/wait.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		"minishell.h"

static int		nbr_pipe(char *input)
{
  int			nbr_pipe;
  int			index;

  index = 0;
  nbr_pipe = 0;
  while (input[index] != 0)
    {
      if (input[index] == '|')
	nbr_pipe++;
      index++;
    }
  return (nbr_pipe);
}

static int		**ini_pipe(int nbr_of_pipe, int **tab_pipe_fd)
{
  int		index;

  index = 0;
  while (index < nbr_of_pipe)
    {
      if (pipe(tab_pipe_fd[index]) == -1)
	exit (my_puterror("Error: pipe is not creat propely"));
      index++;
    }
  return (tab_pipe_fd);
}

int		**close_tab_pipe(int **tab_pipe_fd,
				 int one_ellem,
				 bool need_close[2])
{
  int		index;

  index = 0;
  while (tab_pipe_fd[index] != NULL)
    {
      if (index != one_ellem)
	{
	  if (index + 1 != one_ellem)
	    close(tab_pipe_fd[index][0]);
	  close(tab_pipe_fd[index][1]);
	}
      else
	{
	  if (need_close[1] == TRUE)
	    close(tab_pipe_fd[index][1]);
	  if (need_close[0] == TRUE)
	    close(tab_pipe_fd[index][0]);
	}
      index++;
    }
  return (tab_pipe_fd);
}

static char 			**schedule_multi_pipe(int **tab_pipe_fd,
						      int nbr_of_pipe,
						      char **env,
						      char **command)
{
  int			index;
  int			*pid;
  int			result;

  if ((pid = malloc(sizeof(int) * (nbr_of_pipe + 1))) == NULL)
    return (0);
  index = 1;
  if ((pid[0] = fork()) == 0)
    first_command(tab_pipe_fd, command[0], env);
  while (index < nbr_of_pipe && pid[index - 1] != 0)
    {
      if ((pid[index] = fork()) == 0)
	mid_command(tab_pipe_fd, index, command[index], env);
      index++;
    }
  if (is_builting(my_str_to_word_tab(command[nbr_of_pipe], ' '), env) == FALSE)
    if (pid[index - 1] != 0 && (pid[nbr_of_pipe] = fork()) == 0)
	last_command(tab_pipe_fd, nbr_of_pipe, command[nbr_of_pipe], env);
  tab_pipe_fd = close_tab_pipe(tab_pipe_fd, -1, NULL);
      index = -1;
  while (++index <= nbr_of_pipe)
    waitpid(pid[index], &result, WCONTINUED);
  return (env);
}

char			**multi_pipe(char *input, char **env)
{
  int			**tab_pipe_fd;
  int			nbr_of_pipe;
  char			**all_command;
  char			**tmp;

  tmp = my_str_to_word_tab(input, '|');
  if ((nbr_of_pipe = nbr_pipe(input)) == -1 ||
      (tab_pipe_fd = my_malloc_tab_tab_int(nbr_of_pipe, 2)) == NULL ||
      ((all_command = clean_all_input(tmp, TRUE)) == NULL))
    return (env);
  tab_pipe_fd = ini_pipe(nbr_of_pipe, tab_pipe_fd);
  env = schedule_multi_pipe(tab_pipe_fd, nbr_of_pipe, env, all_command);
  free_tab(all_command);
  my_free_tab_tab_int(tab_pipe_fd);
  return (env);
}
