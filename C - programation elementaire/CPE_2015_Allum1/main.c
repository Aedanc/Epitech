/*
** main.c for  in /home/fortevg/rendu/CPE/CPE_2015_Allum1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Feb  9 23:01:46 2016 Forteville Gabriel
** Last update Fri Feb 26 21:55:03 2016 Forteville Gabriel
*/

#include <unistd.h>
#include "allum1.h"
#include "resource/resource.h"

void		set_data(t_game *data, char *strline,
			 char *strmatch, int i)
{
  if (i == 0)
    {
      data->line[0] = 1;
      data->line[1] = 3;
      data->line[2] = 5;
      data->line[3] = 7;
      data->nbrline = 3;
    }
  i = 0;
  while (i++ != 4096)
    strline[i] = 0;
  i = 0;
  while (i++ != 4096)
    strmatch[i] = 0;
}

void		printresult(int i, char *strline, char *strmatch)
{
  if (i == 0)
    my_putstr("Player removed ");
  else
    my_putstr("AI removed ");
  if (i == 0)
    write(1, &strmatch[0], 1);
  else
    write(1, "1", 1);
  my_putstr(" match(es) from line ");
  if (i == 0)
    write(1, &strline[0], 1);
  else
    {
      i = i + '0';
      write (1, &i, 1);
    }
  write (1, "\n", 1);
}

void		iaturn(t_game *data, char *strline, char *strmatch)
{
  int		i;

  i = 0;
  my_putstr("\nAI's turn...\n");
  while (data->line[i] <= 0)
    i++;
  data->line[i]--;
  printresult(i + 1, strline, strmatch);
}

void		end(int check, t_game *data, t_game *save)
{
  printplateau(data, save);
  if (check % 2 == 0)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  else
    my_putstr("You lost, too bad..\n");
}

int		main()
{
  t_game	data;
  t_game	save;
  int		check;
  char		strline[4096];
  char		strmatch[4096];

  set_data(&data, strline, strmatch, check = 0);
  save = data;
  while (data.line[0] != 0 || data.line[1] != 0 ||
  	 data.line[2] != 0  || data.line[3] != 0)
    {
      printplateau(&data, &save);
      if (check % 2 == 0)
	{
	  my_putstr("\nYour turn:\n");
	  checkargumain(strline, strmatch, &data);
	  data.line[strline[0] - '1'] -= strmatch[0] - '0';
	  printresult(0, strline, strmatch);
	}
      else
	iaturn(&data, strline, strmatch);
      check++;
    }
  end(check, &data, &save);
  return (0);
}
