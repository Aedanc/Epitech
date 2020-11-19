/*
** add_employee.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 14:41:41 2016 Forteville Gabriel
** Last update Fri Jul 01 19:30:48 2016 Forteville Gabriel

*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<struct.h>
#include	<string.h>
#include	"basic.h"

static void		init(t_employee **employee, char **line)
{
  if ((*employee = malloc(sizeof(t_employee))) == NULL)
    error("malloc fail");
  (*employee)->last_name = strdup(line[1]);
  (*employee)->first_name = strdup(line[2]);
  (*employee)->position = strdup(line[3]);
  (*employee)->zipcode = strdup(line[4]);
  (*employee)->id = strdup(line[5]);
  (*employee)->id[strlen((*employee)->id) - 1] = 0;
  (*employee)->next = NULL;
}

void		add_employee(t_employee **employee, char **line)
{
  t_employee	*tmp;

  tmp = (*employee);
  if (*employee == NULL && tablen(line) == 6)
    init(employee, line);
  else if (tablen(line) == 6)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      if ((tmp->next = malloc(sizeof(t_employee))) == NULL)
	error("malloc fail");
      tmp->next->last_name = strdup(line[1]);
      tmp->next->first_name = strdup(line[2]);
      tmp->next->position = strdup(line[3]);
      tmp->next->zipcode = strdup(line[4]);
      tmp->next->id = strdup(line[5]);
      tmp->next->id[strlen(tmp->next->id) - 1] = 0;
      tmp->next->next = NULL;
    }
}
