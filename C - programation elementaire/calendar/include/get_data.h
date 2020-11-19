/*
** get_data.h for calendar in /home/fortevg/rendu/calendar/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 15:39:34 2016 Forteville Gabriel
** Last update Sat Jul 02 15:11:54 2016 Forteville Gabriel
*/

#include	"struct.h"

#ifndef		_GET_DATA_H_
# define	_GET_DATA_H_

void		add_employee(t_employee **mployee, char **line);

void		fire_employee(t_employee **employee, char **line);

void		add_meeting(t_meeting **meeting, char **line);

void		print_order_name(t_employee *employee, char **data);

void		print_meeting(t_meeting *meeting, t_employee *employee,
			      char **data);

#endif		/* !_GET_DATA_H_ */
