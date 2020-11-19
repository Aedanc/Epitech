/*
** fire_employee.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 20:54:21 2016 Forteville Gabriel
** Last update Fri Jul 01 22:32:29 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		<string.h>
#include		"struct.h"

static void		free_elem(t_employee *elem)
{
  free(elem->id);
  free(elem->first_name);
  free(elem->last_name);
  free(elem->position);
  free(elem->zipcode);
  free(elem);
}

static t_employee	*free_one_elem(t_employee *src, t_employee *elem)
{
  t_employee		*tmp;

  tmp = src;
  if (src == elem)
    src = src->next;
  else if (elem->next != NULL)
    {
      while (tmp->next != elem)
	tmp = tmp->next;
      tmp->next = tmp->next->next;
    }
  else
    {
      while (tmp->next->next != NULL)
	tmp = tmp->next;
      tmp->next = NULL;
    }
  free_elem(elem);
  elem = NULL;
  return (src);
}

void			fire_employee(t_employee **employee, char **line)
{
  int		index;
  t_employee	*tmp;

  index = 1;
  while	(line[index] != NULL)
    {
      tmp = (*employee);
      while (tmp != NULL)
	{
	  if (strcmp(tmp->id, line[index]) == 0)
	    {
	      (*employee) = free_one_elem((*employee), tmp);
	      break ;
	    }
	  if (tmp != NULL)
	    tmp = tmp->next;
	}
      index++;
    }
}
