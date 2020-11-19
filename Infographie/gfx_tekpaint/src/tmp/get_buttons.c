/*
** get_buttons.c for get_buttons in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Mon Jan 25 18:18:29 2016 baldas
** Last update Mon Jan 25 18:47:57 2016 baldas
*/

#include <lapin.h>
#include "../../include/paint.h"

void	get_buttons_3(t_data *data)
{
  data->buttons[8].pos1.x = 105;
  data->buttons[8].pos1.y = 17;
  data->buttons[8].pos2.x = 145;
  data->buttons[8].pos2.y = 54;
  data->buttons[8].button = 128;
  data->buttons[9].pos1.x = 167;
  data->buttons[9].pos1.y = 17;
  data->buttons[9].pos2.x = 207;
  data->buttons[9].pos2.y = 54;
  data->buttons[9].button = 256;
  data->buttons[10].pos1.x = 231;
  data->buttons[10].pos1.y = 17;
  data->buttons[10].pos2.x = 270;
  data->buttons[10].pos2.y = 55;
  data->buttons[10].button = 512;
}

void	get_buttons_2(t_data *data)
{
  data->buttons[4].pos1.x = 19;
  data->buttons[4].pos1.y = 336;
  data->buttons[4].pos2.x = 58;
  data->buttons[4].pos2.y = 376;
  data->buttons[4].button = 8;
  data->buttons[5].pos1.x = 19;
  data->buttons[5].pos1.y = 394;
  data->buttons[5].pos2.x = 58;
  data->buttons[5].pos2.y = 433;
  data->buttons[5].button = 16;
  data->buttons[6].pos1.x = 19;
  data->buttons[6].pos1.y = 455;
  data->buttons[6].pos2.x = 58;
  data->buttons[6].pos2.y = 498;
  data->buttons[6].button = 32;
  data->buttons[7].pos1.x = 19;
  data->buttons[7].pos1.y = 514;
  data->buttons[7].pos2.x = 58;
  data->buttons[7].pos2.y = 555;
  data->buttons[7].button = 64;
  get_buttons_3(data);
}

void	get_buttons(t_data *data)
{
  data->buttons[0].pos1.x = 19;
  data->buttons[0].pos1.y = 93;
  data->buttons[0].pos2.x = 58;
  data->buttons[0].pos2.y = 132;
  data->buttons[0].button = 1;
  data->buttons[1].pos1.x = 19;
  data->buttons[1].pos1.y = 156;
  data->buttons[1].pos2.x = 58;
  data->buttons[1].pos2.y = 196;
  data->buttons[1].button = 2;
  data->buttons[2].pos1.x = 19;
  data->buttons[2].pos1.y = 219;
  data->buttons[2].pos2.x = 58;
  data->buttons[2].pos2.y = 257;
  data->buttons[2].button = 3;
  data->buttons[3].pos1.x = 19;
  data->buttons[3].pos1.y = 277;
  data->buttons[3].pos2.x = 58;
  data->buttons[3].pos2.y = 316;
  data->buttons[3].button = 4;
  get_buttons_2(data);
}
