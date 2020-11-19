/*
** remplicage.c for  in /home/fortevg/rendu/infographie/gfx_tekpaint/src/gab
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 25 19:33:57 2016 Forteville Gabriel
** Last update Tue Jan 26 21:41:31 2016 baldas
*/

#include <lapin.h>
#include "../../include/paint.h"
#include "../../include/basics.h"

void			fill_north(t_bunny_pixelarray *pix, t_list *list,
			      t_color *oldcolor, t_data	*data)
{
  t_color		*col;

  list->pos->y--;
  col = tekgetpixel(pix, list->pos);
  if (col->full== oldcolor->full)
    {
      tekpixel(pix, list->pos, &data->color);
      tek_put_in_end_list(list, list->pos);
    }
  list->pos->y++;
}

void			fill_east(t_bunny_pixelarray *pix, t_list *list,
			      t_color *oldcolor, t_data	*data)
{
  t_color		*col;

  list->pos->x++;
  col = tekgetpixel(pix, list->pos);
  if (col->full== oldcolor->full)
    {
      tekpixel(pix, list->pos, &data->color);
      tek_put_in_end_list(list, list->pos);
    }
  list->pos->y--;
}

void			fill_west(t_bunny_pixelarray *pix, t_list *list,
			      t_color *oldcolor, t_data	*data)
{
  t_color		*col;

  list->pos->x--;
  col = tekgetpixel(pix, list->pos);
  if (col->full== oldcolor->full)
    {
      tekpixel(pix, list->pos, &data->color);
      tek_put_in_end_list(list, list->pos);
    }
  list->pos->x++;
}

void			fill_south(t_bunny_pixelarray *pix, t_list *list,
			      t_color *oldcolor, t_data	*data)
{
  t_color		*col;

  list->pos->y++;
  col = tekgetpixel(pix, list->pos);
  if (col->full== oldcolor->full)
    {
      tekpixel(pix, list->pos, &data->color);
      tek_put_in_end_list(list, list->pos);
    }
  list->pos->y--;
}

void				bucket(void *my_data)
{
  t_list			*list;
  t_list			*tmp;
  t_color			*oldcolor;
  const t_bunny_position	*pos;
  t_data			*data;

  data = my_data;
  pos = bunny_get_mouse_position();
  oldcolor = tekgetpixel(data->draw, (t_bunny_position*)pos);
  list = NULL;
  tmp = malloc(sizeof(tmp));
  tmp->pos = (t_bunny_position*)pos;
  tmp->next = list;
  list = tmp;
  while (list != NULL)
    {
      fill_north(data->draw, list, oldcolor, data);
      fill_east(data->draw, list, oldcolor, data);
      fill_west(data->draw, list, oldcolor, data);
      fill_south(data->draw, list, oldcolor, data);
      tmp = list;
      list = list->next;
      bunny_free(tmp);
    }
}
