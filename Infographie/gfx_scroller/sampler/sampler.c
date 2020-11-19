/*
** sampler.c for  in /home/anthony/documents/repository/gfx_scroller/Sampler
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 19:59:16 2016 anthony
** Last update Sun Mar 20 21:57:23 2016 anthony
*/

#include		<sys/time.h>
#include		<string.h>
#include		"sampler.h"
#include		<stdio.h>

void			*init_sampler(t_bunny_window *win)
{
  t_sampler		*sampler;
  char			*sample_file;

  sampler = malloc(sizeof(t_sampler));
  sampler->win = win;
  if ((sampler->part = bunny_load_ini
       ("ressources/modlike/beverly.bsf")) == NULL)
    return (NULL);
  sample_file = new_file("ressources/modlike/", bunny_ini_get_field
			 (sampler->part, "track1", "sample", 0));
  if (sample_file == NULL)
    return (NULL);
  if ((sampler->effect = bunny_load_effect(sample_file)) == NULL)
    return (NULL);
  sampler->curs_dur = 0;
  sampler->curs_fq = 0;
  sampler->frequency = get_new_frequency(sampler->part, &sampler->curs_fq);
  if (sampler->frequency == -1)
    return (NULL);
  sampler->duration = get_new_duration(sampler->part, &sampler->curs_dur);
  if (sampler->duration == -1)
    return (NULL);
  bunny_sound_pitch(&sampler->effect->sound, sampler->frequency / 250);
  bunny_sound_loop(&sampler->effect->sound, 1);
  return (sampler);
}

void			destroy_sampler(void *data)
{
  t_sampler		*sampler;

  sampler = data;
  bunny_delete_ini(sampler->part);
  bunny_delete_sound(&sampler->effect->sound);
  free(sampler);
}

suseconds_t		get_ms(struct timeval *time)
{
  suseconds_t		micro;

  micro = time->tv_sec * 1000 + time->tv_usec / 1000;
  return (micro);
}


int			play_sound(t_sampler *sampler)
{
  static struct timeval time_begin = {.tv_sec = 0, .tv_usec = 0};
  struct timeval	time_end;

  if (time_begin.tv_usec == 0 && time_begin.tv_sec == 0)
    {
      bunny_sound_play(&sampler->effect->sound);
      gettimeofday(&time_begin, NULL);
    }
  gettimeofday(&time_end, NULL);
  if (get_ms(&time_end) - get_ms(&time_begin) > sampler->duration)
    {
      bunny_sound_stop(&sampler->effect->sound);
      sampler->frequency = get_new_frequency(sampler->part, &sampler->curs_fq);
      if (sampler->frequency == -1)
	return (1);
      sampler->duration = get_new_duration(sampler->part, &sampler->curs_dur);
      if (sampler->duration == -1)
	return (1);
      bunny_sound_pitch(&sampler->effect->sound, sampler->frequency / 255);
      time_begin.tv_usec = 0;
      time_begin.tv_sec = 0;
    }
  return (0);
}

t_bunny_response	sampler_loop(void *data)
{
  (void)data;
  t_sampler		*prog;

  prog = data;
  if (play_sound(prog) == 1)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
