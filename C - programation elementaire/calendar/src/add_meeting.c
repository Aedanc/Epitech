/*
** add_meeting.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Jul 02 10:06:00 2016 Forteville Gabriel
** Last update Sat Jul 02 15:32:17 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<struct.h>
#include	<string.h>
#include	"basic.h"

static void		init(t_meeting **meeting, char **line)
{
  int			index;

  if ((*meeting = malloc(sizeof(t_meeting))) == NULL)
    error("malloc fail");
  (*meeting)->place = strdup(line[1]);
  (*meeting)->date = strdup(line[2]);
  (*meeting)->id = strdup(line[3]);
  (*meeting)->next = NULL;
  if (((*meeting)->id_employee = malloc(sizeof(int) * (tablen(line) - 3))) == NULL)
    error("malloc fail");
  index = 0;
  while (line[index + 4] != NULL)
    {
      (*meeting)->id_employee[index] = atoi(line[index + 4]);
      index++;
    }
  (*meeting)->id_employee[index] = -1;
}

void		add_meeting(t_meeting **meeting, char **line)
{
  t_meeting	*tmp;
  int		index;

  tmp = (*meeting);
  if (*meeting == NULL && tablen(line) > 4)
    init(meeting, line);
  else if (tablen(line) > 4)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      if ((tmp->next = malloc(sizeof(t_meeting))) == NULL)
	error("malloc fail");
      tmp->next->place = strdup(line[1]);
      tmp->next->date = strdup(line[2]);
      tmp->next->id = strdup(line[3]);
      tmp->next->next = NULL;
      if ((tmp->next->id_employee = malloc(sizeof(int) * (tablen(line) - 3))
	   ) == NULL)
	error("malloc fail");
      index = -1;
      while (line[++index + 4] != NULL)
	tmp->next->id_employee[index] = atoi(line[index + 4]);
    }
}
