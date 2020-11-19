/*
** get_bsf_file.c for  in /home/anthony/documents/repository/gfx_scroller/sampler
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 01:43:13 2016 anthony
** Last update Sun Mar 20 03:02:36 2016 anthony
*/

#include		<string.h>
#include		"sampler.h"
#include		<stdio.h>

const char		*get_sample(t_bunny_ini *ini)
{
  return (bunny_ini_get_field(ini, "track1", "sample", 0));
}

double			get_new_frequency(t_bunny_ini *ini, int *cursor)
{
  double		n_frequency;
  const char		*n_frequency_field;

  if ((n_frequency_field =
       bunny_ini_get_field(ini, "track1", "frequency", *cursor)) == NULL)
    {
      *cursor = 0;
      if ((n_frequency_field =
	  bunny_ini_get_field(ini, "track1", "frequency", *cursor)) == NULL)
	return (-1);
    }
  *cursor += 1;
  n_frequency = atof(n_frequency_field);
  return (n_frequency);
}

suseconds_t		get_new_duration(t_bunny_ini *ini, int *cursor)
{
  suseconds_t		n_time;
  const char		*n_time_field;

  if ((n_time_field =
       bunny_ini_get_field(ini, "track1", "duration", *cursor)) == NULL)
    {
      *cursor = 0;
      if ((n_time_field =
	   bunny_ini_get_field(ini, "track1", "duration", *cursor)) == NULL)
	return (-1);
    }
  *cursor += 1;
  n_time = atol(n_time_field);
  return (n_time);
}

char			*new_file(char *path_file, const char *sample_file)
{
  char			*new_file;

  new_file = malloc(strlen(path_file) + strlen(sample_file) + 1);
  new_file = strcpy(new_file, path_file);
  new_file = strcat(new_file, sample_file);
  return (new_file);
}
