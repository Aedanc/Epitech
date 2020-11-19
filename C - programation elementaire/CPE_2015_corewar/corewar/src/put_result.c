/*
** put_result.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Mar 24 00:31:06 2016 Forteville Gabriel
** Last update Sun Mar 27 01:27:19 2016 Hugo Willaume
*/

#include	"op.h"
#include	"virtual.h"
#include	"basics.h"

void		my_putaction(t_champions *champion, int check)
{
  my_putstr("Le joueur ");
  my_putnbr(champion->ch_nb);
  my_putchar('(');
  my_putstr(champion->header->prog_name);
  if (check == WIN)
    my_putstr(") a gagné.\n");
  else
    my_putstr(") est en vie\n");
}
