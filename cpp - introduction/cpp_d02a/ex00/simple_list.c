/*
** simple_list.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02a/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 18:28:30 2017 Forteville Gabriel
** Last update Thu Jan 05 19:26:54 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <stdio.h>
#include "simple_list.h"

unsigned int list_get_size(t_list list)
{
  unsigned int		i = 0;

  while (list != NULL && list->next != NULL)
    {
      list = list->next;
      i++;
    }
  return i;
}

t_bool list_is_empty(t_list list)
{
  return (list) ? TRUE : FALSE;
}

t_bool list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_node	*new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return FALSE;
  new_elem->value = elem;
  new_elem->next = *front_ptr;
  front_ptr = &new_elem;
  return TRUE;
}

t_bool list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_node	*new_elem;
  t_node	*trav;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return FALSE;
  new_elem->value = elem;
  new_elem->next = NULL;
  if ((*front_ptr) == NULL) {
      (*front_ptr) = new_elem;
      return TRUE;
    }
  trav = *front_ptr;
  while (trav->next != NULL)
    trav = trav->next;
  trav->next = new_elem;
  return TRUE;
}

t_bool list_del_elem_at_front(t_list *front_ptr)
{
  t_list *save = front_ptr;

  (*front_ptr) = (*front_ptr)->next;
  free (save);
  return 
}
