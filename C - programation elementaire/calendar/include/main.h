/*
** main.h for calendar in /home/fortevg/rendu/calendar/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 15:58:01 2016 Forteville Gabriel
** Last update Sat Jul 02 12:42:44 2016 Forteville Gabriel
*/

#include	"struct.h"

#ifndef		_MAIN_H_
# define	_MAIN_H_

void		get_data(t_employee **employee, t_meeting **meeting);

void		free_employee(t_employee *list);

void		print_order_name(t_employee *employee);

void		free_meeting(t_meeting *list);

#endif		/* !_MAIN_H_ */
