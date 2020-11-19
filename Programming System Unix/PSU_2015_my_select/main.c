/*
** main.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Dec  7 14:26:15 2015 Forteville Gabriel
** Last update Sun Dec 13 21:18:17 2015 Forteville Gabriel
*/

#include <ncurses.h>
#include <stdlib.h>
#include "list.h"
#include "my.h"

int		supr_this(t_list **argu, int i, int ac)
{
  t_list	*tmp;

  if (ac <= 2)
    {
      endwin();
      exit (0);
    }
  tmp = *argu;
  if (i == 1)
    (*argu) = (*argu)->next;
  while (i > 2)
    {
      tmp = tmp->next;
      i--;
    }
  tmp->next = tmp->next->next;
  return (ac - 1);
}

int		send(t_list **argu)
{
  t_list	*tmp;

  tmp = *argu;
  while (tmp->next != NULL)
    {
      if (tmp->select == 1)
	{
	  my_putstr(tmp->str);
	  my_putstr(" ");
	}
      tmp = tmp->next;
    }
  free(tmp);
  return (0);
}

int		tag_this(t_list **argu, int i)
{
  t_list	*tmp;

  tmp = *argu;
  while (i != 1)
    {
      tmp = tmp->next;
      i--;
    }
  if (tmp->select == 1)
    tmp->select = 0;
  else
    tmp->select = 1;
  return (258);
}

int		my_select(t_list **argu, int i, int ac)
{
  int		ch;

  refresh();
  ch = getch();
  if (ch == 259)
    i--;
  else if (ch == 32)
    ch = tag_this(argu, i);
  else if (ch == 263 ||ch == 330)
    ac = supr_this(argu, i, ac);
  if (ch == 258)
    i++;
  else if (ch == 27 ||ch == 10)
    return (ch);
  if (i >= ac)
    i = 1;
  if (i <= 0)
    i = ac - 1;
  clear();
  my_show_list(*argu, i);
  ch =  my_select(argu, i, ac);
  return (ch);
}

int		main(int ac, char **av)
{
  t_list	*argu;
  int		tmp;

  tmp = ac;
  argu = NULL;
  newterm(NULL, stdin, stdin);
  cbreak();
  curs_set(0);
  while (ac > 0)
    {
      my_put_in_list(&argu, av[ac], ac);
      ac--;
    }
  my_show_list(argu, 1);
  refresh();
  noecho();
  keypad(stdscr, TRUE);
  tmp = my_select(&argu, 1, tmp);
  endwin();
  if (tmp == 10)
    send(&argu);
  free(argu);
  return (0);
 }
