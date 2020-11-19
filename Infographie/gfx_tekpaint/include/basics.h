/*
** basics.h for basics in /home/baldas/Prog/repos/info/gfx_tekpaint/include
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Thu Jan 21 15:18:44 2016 baldas
** Last update Tue Jan 26 14:29:50 2016 baldas
*/

#ifndef BASICS_H_
# define BASICS_H_

void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 t_color		*color);

void			tekline(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 t_color		*color);

void			tekcircle(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  double		r,
				  t_color		*color);

void			set_black(t_bunny_pixelarray	*pix);

#endif /* BASICS_H_ */
