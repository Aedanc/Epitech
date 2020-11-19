/*
** print_order_name.c for calendar in /home/fortevg/rendu/calendar/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 22:46:29 2016 Forteville Gabriel
** Last update Sat Jul 02 15:17:44 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include	<string.h>
#include	"struct.h"
#include	"basic.h"

void		print_order_name(t_employee *employee, char **data)
{
  int		index;
  t_employee	*save;

  index = 1;
  save = employee;
  while (data[index] != NULL)
    {
      while (employee != NULL)
	{
	  if (strcmp(employee->id, data[index]) == 0)
	    printf("******************************\n%s %s\nposition: %s\ncity: "
		   "%s\n", employee->first_name, employee->last_name,
		   employee->position, employee->zipcode);
	    employee = employee->next;
	}
      employee = save;
      index++;
    }
}
