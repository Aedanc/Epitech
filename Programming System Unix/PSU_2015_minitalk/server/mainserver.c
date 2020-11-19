/*
** mainserver.c for  in /home/fortevg/rendu/PSU/PSU_2015_minitalk/server
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Feb  3 11:37:05 2016 Forteville Gabriel
** Last update Sun Feb 21 23:26:31 2016 Forteville Gabriel
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "../src/include.h"

static int	g_tab[5];
/*nécésaire pour stocké l'évolution du char et l'utilisation de ping pong*/

void		pid(int sig)
{
  if (sig == SIGUSR1)
    g_tab[3] |= (1 << g_tab[4]);
}

void		catch(int sig)
{
  if (sig == SIGUSR1)
    g_tab[1] |= (1 << g_tab[0]);
  g_tab[0]++;
  if (g_tab[0] == 8 && g_tab[1] != 255)
    {
      write(1, &g_tab[1], 1);
      g_tab[0] = 0;
      g_tab[1] = 0;
    }
}

void		servermainloop()
{
  g_tab[0] = 0;
  g_tab[1] = 0;
  g_tab[3] = 0;
  g_tab[4] = 0;
  signal(SIGUSR1, pid);
  signal(SIGUSR2, pid);
  while (g_tab[4] < 24)
    {
      pause();
      g_tab[4]++;
    }
  signal(SIGUSR1, catch);
  signal(SIGUSR2, catch);
  while (g_tab[1] != 255)
    {
      pause();
      usleep(100);
      kill(g_tab[3], SIGUSR1);
    }
  servermainloop();
}

int		main()
{
  pid_t		servpid;

  servpid = getpid();
  my_put_nbr_base((int)servpid, "0123456789");
  write(1, "\n", 1);
  servermainloop();
  return (0);
}
