/*
** print_meeting.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Jul 02 14:28:19 2016 Forteville Gabriel
** Last update Sat Jul 02 15:41:50 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"struct.h"
#include	"basic.h"

static void	print_employee(int *tab, t_employee *employee)
{
  int		index;
  t_employee	*tmp;

  index = 0;
  printf("%s", "with:");
  while (tab[index] != -1)
    {
      tmp = employee;
      while (tmp != NULL)
	{
	  if (atoi(tmp->id) == tab[index] && tab[index + 1] != -1)
	    printf(" %s %s, ", tmp->first_name, tmp->last_name);
	  else if (atoi(tmp->id) == tab[index] && tab[index + 1] == -1)
	    printf("%s %s\n", tmp->first_name, tmp->last_name);
	  tmp = tmp->next;
	}
      index++;
    }
}

void		print_meeting(t_meeting *meeting, t_employee *employee,
			      char **data)
{
  int		index;
  t_meeting	*save;

  index = 1;
  save = meeting;
  data[tablen(data) - 1][strlen(data[tablen(data) - 1]) - 1] = 0;
  while (data[index] != NULL)
    {
      while (meeting != NULL)
	{
	  if (strcmp(meeting->id, data[index]) == 0)
	    {
	      printf("******************************\nMEETING\ndate: %s\n"
		     "place: %s\n", meeting->date, meeting->place);
	      print_employee(meeting->id_employee, employee);
	    }
	      meeting = meeting->next;
	}
      meeting = save;
      index++;
    }
}
