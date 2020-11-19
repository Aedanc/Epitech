/*
** requirement.c for projTester in /home/fortevg/rendu/projTester
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Wed Jun 22 11:01:49 2016 Gabriel Forteville
** Last update Fri Jun 24 22:38:38 2016 Gabriel Forteville
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_ps_synthesis()
{
  if (fork() == 0)
    {
      execlp("ps", "ps", NULL);
      exit(0);
    }
  else
    wait(NULL);
}
