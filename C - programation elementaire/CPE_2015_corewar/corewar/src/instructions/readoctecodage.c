/*
** readopcodage.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src/instructon
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Mar 23 18:19:47 2016 Forteville Gabriel
** Last update Sun Mar 27 21:13:41 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"basics.h"
#include	"virtual.h"
#include	"op.h"

char		*readoctecodage(t_arena *coloseum,
				t_process *actualprocess)
{
  char		*info;
  char		counter;

  counter = 0;
  if ((info = malloc(sizeof(char) * 4)) == NULL)
    {
      my_putstr("MALLOC ERROR\n");
      exit(1);
    }
  while (counter < 4)
    {
      info[(int)counter] = coloseum->arena[actualprocess->pc + 1] >>
	(6 - counter * 2);
      info[(int)counter] &= 3;
      counter++;
    }
  return (info);
}
