/*
** set_color_in_palet.c for  in /home/anthony/documents/repository/gfx_scroller/plasma
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 18:46:05 2016 anthony
** Last update Sun Mar 20 21:39:48 2016 anthony
*/

#include		"plasma.h"
#include		<stdio.h>
void			palet_yellow(t_color *panel, double m_red,
				     double m_green, double m_blue)
{
  int			i;
  unsigned char		cmp;

  i = 64;
  cmp = 0;
  while (i < 96)
    {
      panel[i].argb[RED_CMP] = 255.0 * m_red;
      panel[i].argb[GREEN_CMP] = cmp * m_green;
      panel[i].argb[BLUE_CMP] = 0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp += 8;
      i++;
    }
  panel[i].argb[RED_CMP] = 255.0 * m_red;
  panel[i].argb[GREEN_CMP] = 255.0 * m_green;
  panel[i].argb[BLUE_CMP] = 0 * m_blue;
  panel[i].argb[ALPHA_CMP] = 255;
}

void			palet_green(t_color *panel, double m_red,
				     double m_green, double m_blue)
{
  int			i;
  unsigned char		cmp;

  cmp = 255;
  i = 96;
  while (i < 128)
    {
      panel[i].argb[RED_CMP] = cmp * m_red;
      panel[i].argb[GREEN_CMP] = 255.0 * m_green;
      panel[i].argb[BLUE_CMP] = 0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp -= 8;
      i++;
    }
  while (i < 160)
    {
      panel[i].argb[RED_CMP] = 0 * m_red;
      panel[i].argb[GREEN_CMP] = 255.0 * m_green;
      panel[i].argb[BLUE_CMP] = 0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      i++;
    }
}

void			palet_cyan(t_color *panel, double m_red,
				   double m_green, double m_blue)
{
  int			i;
  unsigned char		cmp;

  cmp = 0;
  i = 160;
  while (i < 192)
    {
      panel[i].argb[RED_CMP] = 0 * m_red;
      panel[i].argb[GREEN_CMP] = 255.0 * m_green;
      panel[i].argb[BLUE_CMP] = cmp * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp += 8;
      i++;
    }
}

void			palet_blue(t_color *panel, double m_red,
				     double m_green, double m_blue)
{
  int			i;
  unsigned char		cmp;

  i = 192;
  cmp = 255;
  while (i < 224)
    {
      panel[i].argb[RED_CMP] = 0 * m_red;
      panel[i].argb[GREEN_CMP] = cmp * m_green;
      panel[i].argb[BLUE_CMP] = 255.0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp -= 8;
      i++;
    }
}

void			palet_magenta(t_color *panel, double m_red,
				     double m_green, double m_blue)
{
  int			i;
  unsigned char		cmp;

  i = 224;
  cmp = 0;
  while (i < 256)
    {
      panel[i].argb[RED_CMP] = cmp * m_red;
      panel[i].argb[GREEN_CMP] = 0 * m_green;
      panel[i].argb[BLUE_CMP] = 255.0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      cmp += 8;
      i++;
    }
  i = 0;
  while (i < 32)
    {
      panel[i].argb[RED_CMP] = 255.0 * m_red;
      panel[i].argb[GREEN_CMP] = 0 * m_green;
      panel[i].argb[BLUE_CMP] = 255.0 * m_blue;
      panel[i].argb[ALPHA_CMP] = 255;
      i++;
    }
}
