/*
** my_put_in_list.c for  in /home/fortev_g/rendu/CPE_2015_Pushswap
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Nov 17 11:21:21 2015 Gabriel Forteville
** Last update Sun Dec 13 14:16:24 2015 Forteville Gabriel
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../list.h"
#include "../my.h"

int		my_put_in_list(t_list **list, char *str, int ac)
{
  t_list	*elem;
  int		xmax;
  int		ymax;

  getmaxyx(stdscr, ymax, xmax);
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->y = ac - 1;
  elem->x = 0;
  while (elem->y >= ymax)
    {
      elem->y = elem->y - ymax;
      elem->x = elem->x + 20;
    }
  elem->str = str;
  elem->select = 0;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		my_put_in_endlist(t_list **list, char *str)
{
  t_list *elem;
  t_list *tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->str = str;
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

void		my_show_list(t_list *list, int i)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->next != NULL)
    {
      if (i-- == 1)
	attron(A_UNDERLINE);
      if (tmp->select == 1)
	attron(A_REVERSE);
      mvprintw(tmp->y, tmp->x, "%s", tmp->str);
      attroff(A_REVERSE);
      attroff(A_UNDERLINE);
      tmp = tmp->next;
    }
}
