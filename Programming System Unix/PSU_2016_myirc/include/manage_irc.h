/*
** manage_irc.h for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu Jun  8 18:23:00 2017 Pauline Maes
** Last update Sun Jun 11 22:21:11 2017 Pauline Maes
*/

#ifndef		MANAGE_IRC_H_
# define	MANAGE_IRC_H_

#include	"s_client.h"
#include	"s_server.h"

int		my_accept(int, struct sockaddr_in *);
s_client	*add_client(s_client, s_client *, int);
int		manage_error(char *, int);
void		watch_sockets(fd_set *, s_client *, s_server *, int);
int		max_fd(s_client *);

#endif		/* !MANAGE_IRC_H_ */
