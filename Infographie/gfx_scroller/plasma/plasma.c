/*
** plasma.c for  in /home/anthony/documents/repository/gfx_scroller
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 14:43:10 2016 anthony
** Last update Sun Mar 20 22:02:13 2016 anthony
*/

#include		"scroller.h"


#include		<stdio.h>
void			palet_red(t_color *panel,
				  double m_red,
				  double m_green,
				  double m_blue)
{
  int			i;
  int			cmp;

  i = 32;
  cmp = 255;
  while (i < 64)
    {
      panel[i].argb[RED_CMP] = 255 * m_red;
      panel[i].argb[GREEN_CMP] = 0 * m_green;
      panel[i].argb[BLUE_CMP] = cmp * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp -= 8;
      i++;
    }
}

unsigned int		*set_palet(double m_red, double m_green, double m_blue)
{
  unsigned int		*palet;

  palet = malloc(sizeof(unsigned int *) * PALET_SIZE);
  if (palet == NULL)
    return (NULL);
  palet_magenta((t_color *)palet, m_red, m_green, m_blue);
  palet_red((t_color *)palet, m_red, m_green, m_blue);
  palet_yellow((t_color *)palet, m_red, m_green, m_blue);
  palet_green((t_color *)palet, m_red, m_green, m_blue);
  palet_cyan((t_color *)palet, m_red, m_green, m_blue);
  palet_blue((t_color *)palet, m_red, m_green, m_blue);
  return (palet);
}


void			*init_plasma(t_bunny_window *win)
{
  t_plasma		*plasma;

  if ((plasma = malloc(sizeof(t_plasma))) == NULL)
    return (NULL);
  plasma->win = win;
  if ((plasma->pic = bunny_new_pixelarray(WIN_X_VGA, WIN_Y_VGA)) == NULL)
    return (NULL);
  plasma->palet = set_palet(1, 1, 1);
  if (plasma->palet == NULL)
    return (NULL);
  plasma->i = 0;
  init_plasma_computed(plasma);
  return (plasma);
}

t_bunny_response	plasma_loop(void *data)
{
  t_plasma		*prog;

  prog = data;
  if (prog->i >= 3000)
    return (EXIT_ON_SUCCESS);
  display_plasma_effect(prog);
  bunny_blit(&prog->win->buffer, &prog->pic->clipable, NULL);
  bunny_display(prog->win);
  prog->i++;
  return (GO_ON);
}

void			free_plasma(void *data)
{
  t_plasma		*plasma;

  plasma = data;
  free(plasma->palet);
  bunny_delete_clipable(&plasma->pic->clipable);
  free(plasma);
}
