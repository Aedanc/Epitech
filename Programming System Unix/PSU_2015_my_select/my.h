/*
** my.h for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Dec  7 17:34:09 2015 Forteville Gabriel
** Last update Sun Dec 13 13:45:18 2015 Forteville Gabriel
*/

#include "list.h"

void		my_putchar(char c);

int		my_strlen(char *str);

void		my_putstr(char *str);

int		my_put_in_list(t_list **list, char *str, int ac);

int		my_put_in_endlist(t_list **list, char *str);

void		my_show_list(t_list *list, int i);
