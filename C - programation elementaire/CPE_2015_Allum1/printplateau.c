/*
** printplateau.c for  in /home/fortevg/rendu/CPE/CPE_2015_Allum1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Feb 26 15:43:04 2016 Forteville Gabriel
** Last update Fri Feb 26 21:57:16 2016 Forteville Gabriel
*/

#include <unistd.h>
#include "allum1.h"
#include "resource/resource.h"

void		putline(int line, t_game *data, t_game *save)
{
  int		nbrofspace;
  int		morespace;
  int		i;

  i = 0;
  nbrofspace = ((save->line[data->nbrline] - save->line[line])/2);
  morespace =  (save->line[line] - data->line[line]);
  while (i++ != nbrofspace + morespace)
    write(1, " ", 1);
  i = 0;
  while (i++ != data->line[line])
    write(1, "|", 1);
  i = 0;
  while (i++ != nbrofspace)
    write(1, " ", 1);
}

void		printplateau(t_game *data, t_game *save)
{
  int		stop;
  int		asterisk;

  stop = 0;
  asterisk = save->line[save->nbrline] + 2;
  while (asterisk-- > 0)
    write(1, "*", 1);
  write(1, "\n", 1);
  while (stop != data->nbrline + 1)
    {
      write(1, "*", 1);
      putline(stop, data, save);
      write(1, "*\n", 2);
      stop++;
    }
  asterisk = save->line[save->nbrline] + 2;
  while (asterisk-- > 0)
    write(1, "*", 1);
  write(1, "\n", 1);
}
