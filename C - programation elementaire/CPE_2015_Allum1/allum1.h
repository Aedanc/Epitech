/*
** allumin.h for  in /home/fortevg/rendu/CPE/CPE_2015_Allum1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Feb  9 23:07:55 2016 Forteville Gabriel
** Last update Fri Feb 26 19:16:30 2016 Forteville Gabriel
*/

#include	"./resource/resource.h"

# ifndef	ALLUMIN_H_
# define	ALLUMIN_H_
# define	READ_SIZE (1)

typedef struct	s_game
{
  int		line[50];
  int		nbrline;
}		t_game;

void		set_data(t_game *data, char *strline, char *strmatch,
			 int i);
void            putline(int line, t_game *data, t_game *save);
void            printplateau(t_game *data, t_game *save);
char		*get_next_line(const int fd);
void            printplateau(t_game *data, t_game *save);
int             checkarguline(char *argu, t_game *data);
int             checkargumatch(char *argu, char *strline, t_game *data);
void		checkargumain(char *strline, char *strmatch,
			      t_game *data);
# endif		/*ALLUMIN_H_*/
