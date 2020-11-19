/*
** tekalphapixel.h for header tekalphapixel in /home/lecler_1/repository/alphachannel_2020
**
** Made by Anthony Leclerc
** Login   <lecler_1@epitech.net>
**
** Started on  Wed Dec 23 13:25:02 2015 Anthony Leclerc
** Last update Sun Feb 21 05:15:27 2016 anthony
*/

#ifndef			TEKALPHAPIXEL_H_
# define		TEKALPHAPIXEL_H_
# define		UCOLOR
# ifdef			TCOLOR
#  define		COLOR		color.full
#  define		TYPE		t_color *color
# endif
# ifdef			UCOLOR
#  define		COLOR		color
#  define		TYPE		unsigned int color
# endif

# include		<lapin.h>

# define		MASK_RED	0xFF
# define		MASK_GREEN	0xFF00
# define		MASK_BLUE	0xFF0000
# define		MASK_ALPHA	0xFF000000
# define		COL_RED		((COLOR & MASK_RED) >> (8 * (RED_CMP)))
# define		COL_GREEN	((COLOR & MASK_GREEN) >> (8 * (GREEN_CMP)))
# define		COL_BLUE	((COLOR & MASK_BLUE) >> (8 * (BLUE_CMP)))
# define		COL_ALPHA	((COLOR & MASK_ALPHA) >> (8 * (ALPHA_CMP)))
# define		OLD_RED		(pixel[coord].argb[RED_CMP])
# define		OLD_GREEN	(pixel[coord].argb[GREEN_CMP])
# define		OLD_BLUE	(pixel[coord].argb[BLUE_CMP])
# define		OLD_ALPHA	(pixel[coord].argb[ALPHA_CMP])
# define		NEW_RED		OLD_RED
# define		NEW_GREEN	OLD_GREEN
# define		NEW_BLUE	OLD_BLUE
# define		NEW_ALPHA	OLD_ALPHA

void			tekpixel(t_bunny_pixelarray *pix,
				 const t_bunny_position *pos,
				 const TYPE);
/* Put a pixel of the chosen color (with alpha channel)	*/

#endif			/* TEKALPHAPIXEL_H_ */
