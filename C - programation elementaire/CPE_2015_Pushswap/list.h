/*
** list.h for pushswap in /home/fortev_g/rendu/CPE_2015_Pushswap
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Tue Nov 17 11:07:06 2015 Gabriel Forteville
** Last update Sun Nov 22 19:34:31 2015 Gabriel Forteville
*/

#ifndef LIST_H
# define LIST_H

struct		s_list
{
  int		nbr;

  struct s_list *next;
};

int		my_put_in_list(struct s_list **list, int nbr);

#endif
