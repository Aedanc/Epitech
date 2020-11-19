/*
** checkargu.c for  in /home/fortevg/rendu/CPE/CPE_2015_Allum1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Feb 26 15:39:58 2016 Forteville Gabriel
** Last update Fri Feb 26 21:59:00 2016 Forteville Gabriel
*/

#include <unistd.h>
#include "allum1.h"
#include "resource/resource.h"

int		checkarguline(char *argu, t_game *data)
{
  int		i;

  i = 0;
  while (argu[i] != '\n' && argu[i] != 0)
    if (argu[i] < '0' || argu[i] > '9')
      {
	my_putstr("Error: invalid input (positive number expected)\n");
	return (-1);
      }
    else
      i++;
  i = my_get_nbr(argu, 0);
  if (i > data->nbrline + 1 || i == 0 || i == -1)
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  if (data->line[((int)argu[0] - '1')] == 0)
    {
      my_putstr("Error: this line is empty\n");
      return (-1);
    }
  return (0);
}

int		checkargumatch(char *argu, char *strline,
			       t_game *data)
{
  int		i;

  i = 0;
  while (argu[i] != '\n' || argu[0] == '\n')
    if (argu[i] < '0' || argu[i] > '9' || argu[0] == '\n')
      {
	my_putstr("Error: invalid input (positive number expected)\n");
	return (-1);
      }
    else
      i++;
  i = my_get_nbr(argu, 0);
  if (i == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
      if (i > data->line[((int)strline[0] - '1')] || i == -1)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
  return (0);
}

void		checkargumain(char *strline,
			      char *strmatch,
			      t_game *data)
{
  int		stop;

  stop = 0;
  while (stop != 2)
    {
      stop = 0;
      set_data(data, strline, strmatch, 1);
      my_putstr("Line: ");
      read(0, strline, 4096);
      if (checkarguline(strline, data) != -1)
	stop++;
      if (stop == 1)
	{
	  my_putstr("Matches: ");
	  read(0, strmatch, 4096);
	  if (checkargumatch(strmatch, strline, data) != -1)
	    stop++;
	}
    }
}
