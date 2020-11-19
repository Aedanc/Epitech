/*
** my_put_in_list.c for  in /home/fortev_g/rendu/CPE_2015_Pushswap
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Tue Nov 17 11:21:21 2015 Gabriel Forteville
** Last update Fri Nov 20 17:51:18 2015 Gabriel Forteville
*/

#include <stdlib.h>
#include "list.h"

int		my_put_in_list(struct s_list **list, int nbr)
{
  struct s_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->nbr = nbr;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		my_put_in_endlist(struct s_list **list, int nbr)
{
  struct s_list *elem;
  struct s_list *tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->nbr = nbr;
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

void		my_show_list(struct s_list *list)
{
  struct s_list *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_put_nbr(tmp->nbr);
      my_putchar(' ');
      tmp = tmp->next;
    }
  my_putchar('\n');
}
