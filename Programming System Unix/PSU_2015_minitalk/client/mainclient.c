/*
** client.c for  in /home/fortevg/rendu/PSU/PSU_2015_minitalk/client
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Feb  3 14:47:08 2016 Forteville Gabriel
** Last update Sun Feb 21 23:24:53 2016 Forteville Gabriel
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "../src/include.h"

void		sendpid(int pid, int clientpid)
{
  int		check;
  int		tmp;

  check = 0;
  while (check < 24)
    {
      tmp = clientpid >> check;
      if ((tmp & 1) == 1)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      usleep(1);
      check++;
    }
}

void		catch(int sig)
{
  signal(sig, catch);
}

void		sendsignal(char tmp, pid_t pid)
{
  usleep(1);
  if ((tmp & 1) == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  if (usleep(5000) != -1)
    sendsignal(tmp, pid);
}

int		main(int ac, char **av)
{
  pid_t		pid;
  int		check;
  char		tmp;

  if (ac != 3)
    return (write(1, "error: client need 2 argument\n", 31));
  sendpid(pid = my_get_nbr(av[1], 0), getpid());
  ac = -1;
  signal(SIGUSR1, catch);
  while (av[2][++ac] != 0)
    {
      check = -1;
      while (++check <= 7)
	{
	  tmp = av[2][ac] >> check;
	  sendsignal(tmp, pid);
	}
    }
  check = -1;
  while (++check <= 7)
    {
      tmp = 255 >> check;
      sendsignal(tmp, pid);
    }
  return (0);
}
