/*
** my_cd.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Apr  5 15:54:08 2016 Forteville Gabriel
** Last update Fri May 13 14:54:28 2016 Forteville Gabriel
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<unistd.h>
#include 	<stdlib.h>
#include	"minishell.h"

static char	**inerror(char **env)
{
  my_puterror("cd: incorrect path\n");
  return (env);
}

static void	go_home(char **env, char *ff1[], int home)
{
  if (env == NULL || home == -2)
    my_puterror("Error: variable \"HOME\" not found\n");
  else
    {
      if (chdir(my_strcpy(env[home], 5, 0)) == -1)
	my_puterror("Error: chdir can't open the directory, maybe \
variable \"HOME\" is empty\n");
      (*ff1) = tow_to_one("str=PWD=", my_strcpy(env[home], 5, 0), FALSE, TRUE);
    }
}

char		**my_cd(char **input, char **env)
{
  int		home;
  char		*ff1;
  char		**ff2;

  home = -1;
  while (home != -2 && my_strcompare(env[++home], "HOME=", 5) != 5)
    if (env != NULL && env[home + 1] == NULL)
      home = -2;
  if (input[1] == NULL)
    go_home(env, &ff1, home);
  else
    {
      if (chdir(input[1]) == -1)
	return (inerror(env));
      ff1 = tow_to_one("str=PWD=", getcwd(NULL, 0), FALSE, TRUE);
    }
  if (env != NULL)
    env = my_setenv(ff2 = my_str_to_word_tab(ff1, '='), env);
  return (env);
}
