/*
** struct.h for SBMLparser in /home/fortevg/rendu/SBMLparser/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jun 13 17:39:21 2016 Forteville Gabriel
** Last update Wed Jun 15 12:58:11 2016 Forteville Gabriel
*/

#ifndef		_STRUCT_H_
# define	_STRUCT_H_

typedef struct 	s_data
{
  char 		**info_line;
  struct s_data	*next;
}		t_data;

#endif		/* !_STRUCT_H_ */
