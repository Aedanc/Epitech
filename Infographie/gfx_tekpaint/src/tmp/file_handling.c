/*
** file_handling.c for file_handling in /home/hurlu/rendu/gfx_tekpaint
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 22:43:25 2016 Hugo Willaume
** Last update Tue Jan 26 22:56:48 2016 Hugo Willaume
*/

#include <lapin.h>
#include "../../include/paint.h"

void	file_handling(t_data *my_data)
{
  if (my_data->tool == DO_OPEN)
    my_data->draw = user_load(my_data);
  else if (my_data->tool == DO_SAVE)
    simple_save(my_data->draw, my_data);
  else if (my_data->tool == DO_SAVEAS)
    save_as(my_data->draw);
  my_data->tool = 0;
}
