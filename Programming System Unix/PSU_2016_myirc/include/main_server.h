/*
** main.h for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu May 25 16:19:10 2017 Pauline Maes
** Last update Sun Jun 11 22:47:54 2017 Pauline Maes
*/

#ifndef		MAIN_H_
# define	MAIN_H_

#include	"s_server.h"

int		check_args(int, char **, int *);
int		create_socket(int);
int		manage_irc(s_server *);
s_server	*init_server(int, int);

#endif		/* !MAIN_H_ */
