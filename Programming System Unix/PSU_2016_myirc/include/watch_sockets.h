/*
** watch_sockets.h for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 21:58:09 2017 Pauline Maes
** Last update Sun Jun 11 23:16:29 2017 Pauline Maes
*/

#ifndef		WATCH_SOCKETS_H_
# define	WATCH_SOCKETS_H_

#include	"s_client.h"
#include	"s_server.h"

int		max_fd(s_client *);
int		my_accept(int, struct sockaddr_in *);
s_client	*add_client(s_client, s_server *, s_client *, int);
void		handle_input(s_client *, s_client *, s_server *, fd_set *);

#endif		/* !WATCH_SOCKETS_H_ */
