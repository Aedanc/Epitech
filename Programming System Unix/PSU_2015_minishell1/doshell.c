/*
** doshell.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan  4 18:41:47 2016 Forteville Gabriel
** Last update Tue Jan 26 22:37:22 2016 Forteville Gabriel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int		my_exit(char **av)
{
  int		i;
  int		check;

  if (av[1] != NULL && av[2] != NULL)
    return (my_putstr("exit: Expression Syntax.\n"));
  i = 0;
  if (av[1] != NULL)
    {
      i = my_get_nbr(av[1], 0);
      check = 0;
      while (av[1][check] != 0)
	{
	  if (av[1][check] < '0' || av[1][check] > '9')
	    return (my_putstr("exit: Badly formed number.\n"));
	  check++;
	}
    }
  my_putstr("exit\n");
  exit (i);
}

void		free_all2(char **flop, char ***envclean, int i)
{
  i = 0;
  while ((*envclean)[i] != NULL)
    {
      free((*envclean)[i]);
      i++;
    }
  free((*envclean)[i]);
  free((*envclean));
}

int		f(char **env)
{
  int		i;
  int				check;

  i = 0;
  while ((check = my_strcompare("PATH=", env[i], 3) == -1) &&
	 env[i + 1] != NULL)
    i++;
  if (env[i + 1] == NULL)
     return (0);
  if (my_strlen(env[i]) <= 5)
      return (0);
  else
    return (i);
}

int		try_to_exe(char **input, int i, char **env, int result)
{
  char		**envclean;
  char		*flop;

  result = fork();
  if (result != 0)
    wait(&i);
  else
    {
      envclean = my_str_to_word_tab((flop = my_strcpy(env[f(env)], 5, 0)), ':');
      free(flop);
      if (input[0][0] == '/' || input[0][0] == '.')
	exit (result = execve(input[0], input, env));
      result = -1;
      while (envclean[i] != NULL && result == -1)
	{
	  result = execve((flop = my_struni(envclean[i++], input[0])), input, env);
	  free(flop);
	}
      if (my_strcompare("exit", input[0], 6) == 4)
	exit (66);
      free_all2(&flop, &envclean, i);
      exit(result);
    }
  return (WEXITSTATUS(i));
}

void		doshell(char **input, char **env)
{
  int		i;

  if ((i = try_to_exe(input, 0, env, 0)) == 255)
    {
      i = 0;
      while (input[0][i++] != ' ' && input[0][i] != 0);
      write(1, input[0], i);
      my_putstr(": command not found\n");
    }
  else if (i == 66)
    my_exit(input);
}
