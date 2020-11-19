/*
** main.c for  in /home/anthony/documents/repository/gfx_scroller
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 13:36:14 2016 anthony
** Last update Sun Mar 20 23:14:26 2016 anthony
*/

#include		<lapin.h>
#include		<time.h>
#include		"scroller.h"

void			init_fonctions(t_scroller *prog)
{
  prog->init[PLASMA] = init_plasma;
  prog->free[PLASMA] = free_plasma;
  prog->tableau[PLASMA] = plasma_loop;
  prog->init[SCROLL] = init_scroll;
  prog->free[SCROLL] = destroy_scroll;
  prog->tableau[SCROLL] = scroll_loop;
}

int			main()
{
  t_scroller		prog;
  int			i;

  prog.win = bunny_start(WIN_X_VGA, WIN_Y_VGA, 0, "Scroller!");
  if (prog.win == NULL)
    return (1);
  i = 0;
  srand(time(NULL));
  bunny_set_maximum_ram(20000000);
  init_fonctions(&prog);
  while (i < NB_ANIM)
    {
      bunny_set_loop_main_function(prog.tableau[i]);
      if ((prog.data_anim = prog.init[i](prog.win)) == NULL)
	return (1);
      if (bunny_loop(prog.win, 100, prog.data_anim) != EXIT_ON_SUCCESS)
	{
	  prog.free[i](prog.data_anim);
	  return (1);
	}
      prog.free[i](prog.data_anim);
      i++;
    }
  bunny_stop(prog.win);
  return (0);
}
