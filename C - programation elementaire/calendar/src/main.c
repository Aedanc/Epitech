/*
** main.c for calendar in /home/fortevg/rendu/calendar
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jun 30 14:46:59 2016 Gabriel Forteville
** Last update Sat Jul 02 12:42:47 2016 Forteville Gabriel
*/

#include		<unistd.h>
#include		"struct.h"
#include		"main.h"
#include <stdio.h>

int			main()
{
  t_employee		*employee;
  t_meeting		*meeting;

  employee = NULL;
  meeting = NULL;
  get_data(&employee, &meeting);
  free_meeting(meeting);
  free_employee(employee);
  return (0);
}
