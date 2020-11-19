/*
** main.c for  in /home/fortev_g/rendu/CPE_2015_Pushswap
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Tue Nov 17 13:06:09 2015 Gabriel Forteville
** Last update Tue Nov 24 14:43:34 2015 Gabriel Forteville
*/
#include <stdlib.h>
#include "list.h"

int	ra(struct s_list **lista, int wis)
{
  struct s_list	*tmpend;
  struct s_list	*tmpstart;

  while (wis > 0)
    {
      tmpend = *lista;
      tmpstart = *lista;
      *lista = (*lista)->next;
      while (tmpend->next != NULL)
	tmpend = tmpend->next;
      tmpend->next = tmpstart;
      tmpstart->next = NULL;
      wis--;
      my_putstr("ra ");
    }
  return (0);
}

int	rra(struct s_list **lista, int wis)
{
  struct s_list *tmp;

  while (wis > 0)
    {
      tmp = *lista;
      while (tmp->next->next != NULL)
	tmp = tmp->next;
      tmp->next->next = *lista;
      *lista = tmp->next;
      tmp->next = NULL;
      wis--;
      my_putstr("rra ");
    }
  return (0);
}

int	the_smaller(struct s_list **lista)
{
  struct s_list *tmp;
  int		smaller;
  int		i;
  int		where;

  tmp = *lista;
  where = 0;
  i = 0;
  smaller = 2147483647;
  while (tmp != NULL)
    {
      if (smaller >= tmp->nbr)
	{
	  smaller = tmp->nbr;
	  where = i;
	}
      tmp = tmp->next;
      i++;
    }
  return (where);
}

int sort(struct s_list **lista, int ac)

{
  struct s_list *listb;
  int		wis;

  listb = NULL;
  while ((*lista)->next != NULL)
    {
      wis = the_smaller(lista);
      if (wis >= ac / 2)
	rra(lista, ac - wis);
      else
	ra(lista, wis);
      my_put_in_list(&listb, (*lista)->nbr);
      *lista = (*lista)->next;
      my_putstr("pb ");
      ac--;
    }
  while (listb->next != NULL)
    {
      my_put_in_list(lista, listb->nbr);
      listb = listb->next;
      my_putstr("pa ");
    }
  my_put_in_list(lista, listb->nbr);
  return (0);
}

int	main(int ac, char **av)
{
  struct s_list *lista;
  struct s_list *tmp;
  int		i;

  if (ac == 1)
    return (0);
  i = 2;
  lista = NULL;
  my_put_in_list(&lista, my_get_nbr(av[i - 1]));
  while (av[i] != '\0')
    my_put_in_endlist(&lista, my_get_nbr(av[++i - 1]));
  tmp = lista;
  while (tmp->next != NULL  && tmp->nbr <= tmp->next->nbr)
    tmp = tmp->next;
  if (tmp->next == NULL)
    {
      my_putchar('\n');
      return (0);
    }
  sort(&lista, ac - 1);
  my_putstr("pa\n");
  return (0);
}
