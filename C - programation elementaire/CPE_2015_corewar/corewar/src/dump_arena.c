/*
** dumpme.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Mar 25 13:59:18 2016 Forteville Gabriel
** Last update Sun Mar 27 23:24:51 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"

void		putline(char *str, int getthrumem)
{
  int		i;

  i = 0;
  my_putnbrhex(getthrumem);
  my_putstr("    : ");
  while (i < 32)
    {
      my_putnbrhexspe((unsigned char)str[i], "0123456789ABCDEF");
      my_putstr(" ");
      i++;
    }
  my_putstr("\n");
}

void		dump_arena(t_arena *coloseum, t_champions *champ)
{
  int		getthrumem;
  char		str[32];
  int		counter;

  getthrumem = 0;
  while (getthrumem < MEM_SIZE)
    {
      counter = 0;
      while (getthrumem < MEM_SIZE && counter < 32)
	{
	  str[counter] = coloseum->arena[getthrumem];
	  getthrumem++;
	  counter++;
	}
      putline(str, getthrumem - 32);
    }
  free_champs(&champ);
  free(coloseum);
  exit (0);
}
