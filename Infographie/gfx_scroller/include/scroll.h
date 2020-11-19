/*
** scroll.h for  in /home/anthony/documents/repository/gfx_scroller/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 15:26:02 2016 anthony
** Last update Sun Mar 20 13:35:38 2016 anthony
*/

#ifndef			SCROLL_H_
# define		SCROLL_H_

# include		"scroller.h"

typedef enum		e_speed
  {
    NO_SPEED,
    SSLOW,
    SLOW,
    MEDIUM,
    FAST,
    SFAST,
  }			t_speed;

# define		PATH_CLOUD_0	"ressources/picture/nuages0.png"
# define		PATH_CLOUD_1	"ressources/picture/nuages1.png"
# define		PATH_MOUNT	"ressources/picture/montagnes.png"
# define		PATH_FENCE	"ressources/picture/barriere.png"

typedef enum		e_background
  {
    BG_CLOUDS,
    BG_MOUNTAIN,
    BG_FENCE,
    BG_TEXT,
    MAX_BGRD
  }			t_background;

typedef struct		s_info_scroll
{
  t_bunny_picture	*pic;
  t_bunny_position	blit_1;
  t_bunny_position	blit_2;
  t_speed		bgrd_speed;
  int			i;
}			t_info_scroll;

typedef	struct		s_scroll
{
  t_bunny_window	*win;
  t_sampler		*music;
  t_info_scroll		bgrd[MAX_BGRD];
  int			count_speed;
}			t_scroll;

void			destroy_scroll(void		*data);

void			*init_scroll(t_bunny_window	*win);

t_bunny_response	scroll_loop(void		*data);

void			scrolling(t_bunny_window	*win,
				  t_info_scroll		*prog);

/*			Scrolling background		*/

t_info_scroll		*new_cloud_scrolling(const char	*path,
					     t_info_scroll *infos,
					     t_speed	speed);

t_info_scroll		*new_mountain_scroll(const char	*path,
					     t_info_scroll *infos,
					     t_speed	speed);
t_info_scroll		*new_fence_scroll(const char	*path,
					  t_info_scroll *infos,
					  t_speed	speed);

t_info_scroll		*new_text_scroll(const char	*path,
					 t_info_scroll *infos,
					 t_speed	speed,
					 const t_bunny_position *space);

#endif			/* SCROLL_H_ */
