/*
** main.c for  in /home/hurlu/rendu/CPE_2015_corewar
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:21:36 2016 Hugo Willaume
** Last update Sun Mar 27 23:32:36 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"
#include	"op.h"

void		free_champs(t_champions **champs)
{
  t_champions	*tmp;

  while ((*champs) != NULL)
    {
      tmp = (*champs);
      free(tmp);
      if ((*champs) != NULL)
	(*champs) = (*champs)->next;
    }
}

void		check_defines()
{
  if (MEM_SIZE < 0)
    {
      my_putstr("Negative memory\n");
      exit (1);
    }
  if (COMMENT_CHAR == LABEL_CHAR || COMMENT_CHAR == DIRECT_CHAR || COMMENT_CHAR
      == SEPARATOR_CHAR || LABEL_CHAR == DIRECT_CHAR || LABEL_CHAR ==
      SEPARATOR_CHAR || DIRECT_CHAR == SEPARATOR_CHAR)
    {
      my_putstr("Similar defined char\n");
      return ;
    }
  if (CYCLE_TO_DIE < 0 || CYCLE_DELTA < 0 || NBR_LIVE < 0 || REG_NUMBER != 16 ||
      IND_SIZE != 2 || REG_SIZE != 4 || DIR_SIZE != REG_SIZE)
    {
      my_putstr("Do not alter values in the .h please. They may affect the");
      my_putstr(" way the Corewars functions in a dangerous way.\n");
      exit (1);
    }
}

int		main(int ac, char **av)
{
  t_arena	*arena;
  t_champions	*champs;
  int		errcode;

  check_defines();
  arena = malloc(sizeof(t_arena));
  champs = NULL;
  if ((errcode = parsing_user(ac, av, &champs, arena)) != 0)
    {
      free_champs(&champs);
      free(arena);
      return (errcode);
    }
  if ((errcode = init_arena_champs(arena, champs)) != 0)
    {
      free_champs(&champs);
      free(arena);
      return (errcode);
    }
  cycle(champs, arena);
  free(arena);
  free_champs(&champs);
  return (0);
}
