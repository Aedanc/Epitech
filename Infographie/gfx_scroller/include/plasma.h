/*
** plasma.h for  in /home/anthony/documents/repository/gfx_scroller/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 14:34:32 2016 anthony
** Last update Sun Mar 20 21:22:19 2016 anthony
*/

#ifndef				PLASMA_H_
# define			PLASMA_H_
# include			<math.h>
# include			"scroller.h"

# define			PALET_SIZE			256
# define			M2_PI				(2 * M_PI)

t_bunny_response		plasma_loop(void		*data);

void				*init_plasma(t_bunny_window	*win);

void				free_plasma(void		*data);

typedef struct			s_plasma
{
  t_bunny_window		*win;
  t_bunny_pixelarray		*pic;
  unsigned int			*palet;
  unsigned int			idx[WIN_X_VGA][WIN_Y_VGA];
  int				i;
}				t_plasma;

unsigned int			*set_palet(double		m_red,
					   double		m_green,
					   double		m_blue);

void				display_plasma_effect(t_plasma	*plasma);

void				init_plasma_computed(t_plasma *pl);


void				palet_yellow(t_color		*panel,
					     double		m_red,
					     double		m_green,
					     double		m_blue);

void				palet_cyan(t_color		*panel,
					   double		m_red,
					   double		m_green,
					   double		m_blue);

void				palet_magenta(t_color		*panel,
					      double		m_red,
					      double		m_green,
					      double		m_blue);

void				palet_green(t_color		*panel,
					    double		m_red,
					    double		m_green,
					    double		m_blue);

void				palet_blue(t_color		*panel,
					   double		m_red,
					   double		m_green,
					   double		m_blue);

void				palet_red(t_color		*panel,
					  double		m_red,
					  double		m_green,
					  double		m_blue);

#endif				/* PLASMA_H_ */
