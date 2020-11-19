/*
** list.h for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Dec  7 14:36:07 2015 Forteville Gabriel
** Last update Sun Dec 13 11:42:04 2015 Forteville Gabriel
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char			*str;
  int			select;
  int			x;
  int			y;
  struct s_list		*next;
}      		t_list;

#endif
