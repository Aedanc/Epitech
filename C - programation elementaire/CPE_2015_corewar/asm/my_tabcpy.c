/*
** my_tabcpy.c for my_tabcpy in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri Mar 25 04:11:35 2016 Hugo Baldassin
** Last update Fri Mar 25 04:21:17 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"my.h"
#include	"asm.h"

char		**my_tabcpy(char **tab)
{
  int		y;
  int		len;
  char		**tab_cpy;

  y = 0;
  len = my_tablen(tab);
  if (!(tab_cpy = malloc((len + 1) * sizeof(char *))))
    error_displays(-7, 0);
  tab_cpy[len] = NULL;
  while (y < len)
    {
      tab_cpy[y] = my_strcpy(tab[y]);
      y++;
    }
  return (tab_cpy);
}
