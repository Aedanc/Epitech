/*
** sampler.h for  in /home/anthony/documents/repository/gfx_scroller/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 20:00:05 2016 anthony
** Last update Sun Mar 20 04:37:27 2016 anthony
*/

#ifndef			SAMPLER_H_
# define		SAMPLER_H_
# include		<lapin.h>
# include		<sys/time.h>

typedef	struct		s_sampler
{
  t_bunny_window	*win;
  t_bunny_ini		*part;
  t_bunny_effect	*effect;
  int			curs_dur;
  int			curs_fq;
  suseconds_t		duration;
  double		frequency;
}			t_sampler;

void			*init_sampler(t_bunny_window *win);

void			destroy_sampler(void *data);

t_bunny_response	sampler_loop(void *data);

int			play_sound(t_sampler *data);

const char		*get_sample(t_bunny_ini *ini);

double			get_new_frequency(t_bunny_ini *ini, int *cursor);

suseconds_t		get_new_duration(t_bunny_ini *ini, int *cursor);

char			*new_file(char *path_file, const char *sample_file);

#endif			/* SAMPLER_H_ */
