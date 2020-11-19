/*
** scrollingtext.h for  in /home/fortevg/rendu/infographie/gfx_scroller
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Mar 20 04:08:56 2016 Forteville Gabriel
** Last update Sun Mar 20 20:44:59 2016 anthony
*/

#ifndef			SCROLLINGTEXT_H_
# define		SCROLLINGTEXT_H_

# include		<lapin.h>

typedef struct          s_txt
{
  t_bunny_position      pos;
  char                  *text;
  t_bunny_picture       *result;
  t_bunny_picture       *font;
}			t_txt;

/*	BASIC.C		*/

int			nbrinfont(char	c);

/*	///////		*/

/*	SCROLLINGTEXT.C		*/
int			ini_text(t_txt		*data,
				 const char	*c);

void			putletter(int		letter,
				  t_txt		*data,
				  int		counter);

t_bunny_picture		*scrollingtext(char	*c);

/*	///////////////		*/

#endif
