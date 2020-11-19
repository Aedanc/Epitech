/*
** user_loader_saver.c for  in /home/hurlu/rendu/gfx_tekpaint/func_load_bmp
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 20:24:08 2016 Hugo Willaume
** Last update Thu Jan 28 18:38:51 2016 Hugo Willaume
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <lapin.h>
#include <stdio.h>
#include "../../include/paint.h"

void	save_as(t_bunny_pixelarray *pix)
{
  char *name;
  int	i;

  my_putstr("Where and with what name do you want to save your file ?\n");
  my_putstr("(Please enter full path and extension, .epi or .bmp)\n>");
  name = get_next_line(0);
  i = my_strlen(name) - 1;
  if (name[i] == 'p' && name[i - 1] == 'm' && name[i - 2] == 'b'
      && name[i - 3] == '.')
    save_bitmap(name, pix, "scratch");
  else if (name[i] == 'i' && name[i - 1] == 'p' && name [i - 2] == 'e'
	   && name[i - 3] == '.')
    save_epi(name, pix);
  else
    my_putstr("Did not recognize that extension!\n");
}

void	simple_save(t_bunny_pixelarray *pix, t_data *data)
{
  int	i;

  i = 0;
  if ((i = my_strlen(data->name)) != 0)
    {
      i--;
      if (data->name[i] == 'p' && data->name[i - 1] == 'm'
	  && data->name[i - 2] == 'b' && data->name[i - 3] == '.')
	save_bitmap(data->name, pix, data->name);
    }
  else if (data->name[i] == 'i' && data->name[i - 1] == 'p'
	  && data->name[i - 2] == 'e' && data->name[i - 3] == '.')
    save_epi(data->name, pix);
  else
    save_as(pix);
}

t_bunny_pixelarray *load_file(char *name, t_data *data)
{
  int	i;

  i = my_strlen(name) - 1;
  data->name = name;
  if (name[i] == 'p' && name[i - 1] == 'm' && name[i - 2] == 'b'
      && name[i - 3] == '.')
    return (load_bitmap(name));
  else if (name[i] == 'i' && name[i - 1] == 'p' && name [i - 2] == 'e'
	   && name[i - 3] == '.')
    return (load_epi(name));
  else
    my_putstr("Sorry, could not load this unrecognised file format!\n");
  return (NULL);
}

t_bunny_pixelarray	*user_load(t_data *data)
{
  char	*command;
  int	i;
  int	fd;

  i = -1;
  my_putstr("Please enter the name of the file you wish to open :\n >");
  command = get_next_line(0);
  data->name = bunny_malloc(sizeof(char) * (my_strlen(command) + 1));
  while (command[++i] != 0)
    data->name[i] = command[i];
  data->name[i] = 0;
  bunny_free(command);
  if ((fd = open(data->name, O_RDONLY)) == -1)
    {
      my_putstr("Could not load: check your file exists and can be read\n");
      bunny_free(data->name);
      return (data->draw);
    }
  close(fd);
  bunny_delete_clipable(&data->draw->clipable);
  data->draw = load_file(data->name, data);
  data->tool = 0;
  return (data->draw);
}
