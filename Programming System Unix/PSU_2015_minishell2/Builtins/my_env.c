/*
** my_env.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Apr  2 17:50:37 2016 Forteville Gabriel
** Last update Tue Apr 26 17:17:34 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

int		my_env(char **env)
{
  if (env != NULL)
    my_show_word_tab(env);
  return (0);
}
