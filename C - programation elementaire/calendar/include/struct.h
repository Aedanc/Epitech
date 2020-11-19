/*
** struct.h for calendar in /home/fortevg/rendu/calendar/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 30 16:12:04 2016 Forteville Gabriel
** Last update Sat Jul 02 10:11:31 2016 Forteville Gabriel
*/

#ifndef			_STRUCT_H_
# define		_STRUCT_H_

typedef	struct		s_employee
{
  char			*id;
  char			*first_name;
  char			*last_name;
  char			*position;
  char			*zipcode;
  struct s_employee	*next;
}			t_employee;

typedef struct		s_meeting
{
  char			*id;
  char			*date;
  char			*place;
  int			*id_employee;
  struct s_meeting	*next;
}			t_meeting;

#endif			/* !_STRUCT_H_ */
