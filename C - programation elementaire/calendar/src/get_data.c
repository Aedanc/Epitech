
/*
** recup_data.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 13:56:10 2016 Forteville Gabriel
** Last update Sat Jul 02 13:18:29 2016 Forteville Gabriel
*/

#define			_GNU_SOURCE
#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		"basic.h"
#include		"struct.h"
#include		"get_data.h"

static void		set_line(char **line, size_t *len)
{
  (*len) = 0;
  free((*line));
  (*line) = NULL;
}

void			get_data(t_employee **employee, t_meeting **meeting)
{
  char			*line;
  size_t		len;
  char			**data;

  len = 0;
  line = NULL;
  while (getline(&line, &len, stdin) > 0 && (strcmp(line, "END") != 0))
    {
      data = my_str_to_wordtab(line, " ");
      if (strcmp(data[0], "new_employee") == 0)
	add_employee(employee, data);
      if (strcmp(data[0], "new_meeting") == 0)
	add_meeting(meeting, data);
      if (strcmp(data[0], "fire") == 0)
	fire_employee(employee, data);
      if (strcmp(data[0], "info_employees") == 0)
	print_order_name((*employee), data);
      if (strcmp(data[0], "info_meetings") == 0)
	print_meeting((*meeting), (*employee), data);
      set_line(&line, &len);
      freetab(data);
    }
  set_line(&line, &len);
}
