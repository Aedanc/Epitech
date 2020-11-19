/*
** in_header.c for in_header in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/baldas/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sat Mar 26 18:36:01 2016 vermeu_v
** Last update Sat Mar 26 19:06:12 2016 vermeu_v
*/

#include	"op.h"

char		*in_header(char *from, char *to)
{
  int		cpt;

  cpt = 0;
  while (from[cpt] != 0)
    {
      to[cpt] = from[cpt];
      cpt++;
    }
  to[cpt] = 0;
  return (to);
}
