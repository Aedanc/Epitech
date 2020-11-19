/*
** epur_tab.c for epur_tab in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Thu Mar 17 18:03:12 2016 Hugo Baldassin
** Last update Wed Mar 23 22:43:43 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"

void		epur_tab(char **tab)
{
  int		y;

  y = 0;
  while (tab[y] != NULL)
    {
      tab[y] = epur_line(tab[y]);
      y++;
    }
}
