/*
** display_plasma_effect.c for  in /home/anthony/documents/repository/gfx_scroller/plasma
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 19:15:18 2016 anthony
** Last update Sun Mar 20 22:57:25 2016 anthony
*/

#include		<time.h>
#include		"plasma.h"

static unsigned int	compute_plasma(t_bunny_position *pos, time_t time_t)
{
  double		index;
  double		ecart_x;
  double		ecart_y;

  (void)time_t;

  index = sin((double)(time_t + pos->x) *  M2_PI / 128.0);
  index += sin((double)(time_t + pos->y) * M2_PI / 128.0);
  index += sin((double)(time_t + 2 *  pos->x + pos->y) * M2_PI / 128.0);
  index += sin((double)(time_t + pos->x + 2 * pos->y * M2_PI / 128.0));
  ecart_x = pos->x - sin((time_t + pos->x) * M2_PI / 128.0);
  ecart_y = pos->y - sin((time_t + pos->y) * M2_PI / 128.0);
  index += (sin(sqrt(10.0 * (ecart_x * ecart_x +
				ecart_y * ecart_y))) * M2_PI / 128.0);
  index *= 0.2;
  return ((unsigned int)abs((index * 255)));
}

void			display_plasma_effect(t_plasma *plasma)
{
  t_bunny_position	pos;
  unsigned int		color;

  pos.y = plasma->pic->clipable.clip_y_position;
  plasma->i++;
  while (pos.y < plasma->pic->clipable.clip_height)
    {
      pos.x = plasma->pic->clipable.clip_x_position;
      while (pos.x < plasma->pic->clipable.clip_width)
	{
	  color = plasma->idx[pos.x][pos.y];
	  tekpixel(plasma->pic, &pos,
		   plasma->palet[(color + plasma->i) % PALET_SIZE]);
	  pos.x++;
	}
      pos.y++;
    }
}

void			init_plasma_computed(t_plasma *pl)
{
  t_bunny_position	pos;
  time_t		time_t;

  pos.y = pl->pic->clipable.clip_y_position;
  while (pos.y < pl->pic->clipable.clip_y_position +
	 pl->pic->clipable.clip_height)
    {
      pos.x = pl->pic->clipable.clip_x_position;
      while (pos.x < pl->pic->clipable.clip_x_position +
	     pl->pic->clipable.clip_width)
	{
	  time_t = time(NULL);
	  pl->idx[pos.x][pos.y] = compute_plasma(&pos, time_t);
	  pos.x++;
	}
      pos.y++;
    }
}
