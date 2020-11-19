/*
** free_linked_list.c for calendar in /home/fortevg/rendu/calendar/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 19:40:38 2016 Forteville Gabriel
** Last update Fri Jul 01 23:04:20 2016 Forteville Gabriel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"struct.h"

void		free_employee(t_employee *list)
{
  t_employee	*tmp;

 tmp = list;
 while (tmp != NULL)
    {
      if (list != NULL)
	{
	  free(list->id);
	  free(list->first_name);
	  free(list->last_name);
	  free(list->position);
	  free(list->zipcode);
	  list = list->next;
	}
      free(tmp);
      tmp = list;
    }
}
