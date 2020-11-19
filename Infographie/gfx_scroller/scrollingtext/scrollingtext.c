/*
** textedéfilant.c for  in /home/fortevg/rendu/infographie/gfx_scroller
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Mar 19 16:33:12 2016 Forteville Gabriel
** Last update Sun Mar 20 23:17:51 2016 anthony
*/

#include		<string.h>
#include		"scroller.h"

int			ini_text(t_txt *data, const char *txt)
{
  data->text = strdup(txt);
  if ((data->font = bunny_load_picture("ressources/font/font8.png")) == NULL)
    return (1);
  data->font->clip_width = 30;
  data->font->clip_height = 34;
  data->result = bunny_new_picture(32 * strlen(data->text), 32);
  return (0);
}

void			putletter(int letter, t_txt *data, int counter)
{
  t_bunny_position	pos;

  pos.y = 0;
  if (letter == -2)
    return ;
  pos.x = data->font->clip_width * counter + 1;
  data->font->clip_x_position = (letter % 9) * 34 + 1;
  data->font->clip_y_position = (letter / 9) * 34 + 1;
  bunny_blit(&data->result->buffer, data->font, &pos);
}

t_bunny_picture			*scrollingtext(char *c)
{
  t_txt			data;
  int			counter;
  int			checkchara;

  counter = 0;
  ini_text(&data, c);
  while (data.text[counter] != 0)
    {
      if ((checkchara = nbrinfont(data.text[counter])) != -1)
	putletter(checkchara, &data, counter);
      counter++;
    }
  free(data.text);
  bunny_delete_clipable(data.font);
  return (data.result);
}
