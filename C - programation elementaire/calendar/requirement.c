/*
** requirement.c for  in /home/fortevg/rendu/calendar
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jun 30 10:27:24 2016 Gabriel Forteville
** Last update Thu Jun 30 14:06:45 2016 Gabriel Forteville
*/

#include		<stdlib.h>
#include		<string.h>

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

int			my_revlist_synthesis(t_list **begin)
{
  t_list		*tmp1;
  t_list		*tmp2;
  t_list		*tmp3;

  tmp1 = (*begin);
  tmp2 = tmp1->next;
  tmp3 = tmp2;
  tmp1->next = NULL;
  while (tmp2 != NULL)
    {
      if (tmp3 != NULL)
	tmp3 = tmp3->next;
      tmp2->next = tmp1;
      tmp1 = tmp2;
      tmp2 = tmp3;
    }
  (*begin) = tmp1;
}


t_list			*my_findnodeeqinlist_synthesis(t_list *begin,
						       void *data_ref,
						       int (*cmp)(void *, void *))
{
  t_list		*tmp;

  tmp = begin;
  while (tmp != NULL && cmp(data_ref, tmp->data) != 0)
    tmp = tmp->next;
  return (tmp);
}
