/*
** parsing.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 15 10:46:36 2016 Forteville Gabriel
** Last update Wed Jun 15 21:22:55 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<unistd.h>
#include	<stdlib.h>

char		parsing(int ac, char *av[])
{
  char		flag;
  char		i_flag;

  i_flag = 0;
  while ((flag = getopt(ac, av, "ih")) != -1)
    {
      if (flag == 'i')
	i_flag = 1;
      else
	return (-1);
    }
  return (i_flag);
}
