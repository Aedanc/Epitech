/*
** main.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan  4 10:07:15 2016 Forteville Gabriel
** Last update Mon Jan 25 15:42:35 2016 Forteville Gabriel
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

void		don_t_stop_me_now(int sig)
{
  if (sig == 2 || sig == 20)
    my_putstr("\n$>");
  else if (sig == 3)
    {
      my_putstr("exit\n");
      exit (0);
    }
}

void		free_all(char (*tmp)[4096], char ***userinput)
{
  int		tab;

  tab = 0;
  while ((*tmp)[tab] != 0)
    {
      (*tmp)[tab] = 0;
      tab++;
    }
  tab = 0;
  while ((*userinput)[tab] != NULL)
    {
      free((*userinput)[tab]);
      tab++;
    }
  free((*userinput)[tab]);
  free((*userinput));
}

int		main(int ac, char **av, char **env)
{
  char	        tmp[4096];
  char		**userinput;
  int		i;

  (void)ac;
  (void)av;
  while (1)
    {
      signal(SIGTSTP, don_t_stop_me_now);
      signal(SIGINT, don_t_stop_me_now);
      my_putstr("$>");
      i = read(0, tmp, 4096);
      if (i == 0)
	{
	  my_putstr("exit\n");
	  exit (0);
	}
      tmp[i - 1] = 0;
      if (tmp[0] != 0)
	{
	  userinput = my_str_to_word_tab(tmp, ' ');
	  doshell(userinput, env);
	  free_all(&tmp, &userinput);
	}
    }
}
