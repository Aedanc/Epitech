/*
** free_meeting.c for calendar in /home/fortevg/rendu/calendar/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Jul 02 12:41:17 2016 Forteville Gabriel
** Last update Sat Jul 02 13:36:58 2016 Forteville Gabriel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"struct.h"

void		free_meeting(t_meeting *list)
{
  t_meeting	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (list != NULL)
	{
	  free(list->id);
	  free(list->date);
	  free(list->place);
	  free(list->id_employee);
	  list = list->next;
	}
      free(tmp);
      tmp = list;
    }
}
