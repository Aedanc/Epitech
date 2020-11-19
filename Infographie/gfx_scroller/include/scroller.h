/*
** scroller.h for  in /home/anthony/documents/repository/gfx_scroller/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 14:05:07 2016 anthony
** Last update Sun Mar 20 23:15:45 2016 anthony
*/

#ifndef			SCROLLER_H_
# define		SCROLLER_H_

# define		WIN_X_VGA	640
# define		WIN_Y_VGA	480
# define		WIN_X_HD	1920
# define		WIN_Y_HD	1080

# include		<lapin.h>
# include		"tekpixel.h"
/*	HEADERS ANIMATIONS
	Mettre votre structure d'animation et vos prototypes de fonctions
	( Il FAUT un t_bunny_window qui prends le pointeur win passé en paramètre
	dans la fonction d'initialisation)
*/

# include		"plasma.h"
# include		"scrollingtext.h"
# include		"sampler.h"
# include		"scroll.h"

/* Ajouter votre animation avec l'ordre dans laquelle
 vous voulez qu'elle apparaisse */

typedef enum		e_animations
  {
    SCROLL,
    PLASMA,
    NB_ANIM
  }			t_animations;

typedef void		(*t_destroy)(void *);
typedef void		*(*t_init)(t_bunny_window *win);

typedef struct		s_scroller
{
  t_bunny_window	*win;
  void			*data_anim;
  t_bunny_loop		tableau[NB_ANIM];
  t_init		init[NB_ANIM];
  t_destroy		free[NB_ANIM];
}			t_scroller;

#endif			/* SCROLLER_H_ */
