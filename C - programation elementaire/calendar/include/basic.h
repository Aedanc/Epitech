/*
** basic.h for calendar in /home/fortevg/rendu/calendar/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 14:26:56 2016 Forteville Gabriel
** Last update Fri Jul 01 20:31:44 2016 Forteville Gabriel
*/

#include	"struct.h"

#ifndef 	_BASIC_H_
# define	_BASIC_H_

char		**my_str_to_wordtab(char *str, char *separator);

void		error(char *error);

int		tablen(char **tab);

void		freetab(char **tab);

void		free_employee(t_employee *list);

#endif		/* !_BASIC_H_ */
