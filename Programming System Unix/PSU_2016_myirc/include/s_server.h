/*
** s_server.h for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 17:50:06 2017 Pauline Maes
** Last update Sun Jun 11 19:01:51 2017 Pauline Maes
*/

#ifndef		S_SERVER_H_
# define	S_SERVER_H_

#include	<sys/types.h>
#include	"s_client.h"
#include	"s_channel.h"

typedef struct	s_server
{
  int	        port;
  int	        fd;
  fd_set	readfds;
  s_channel	*channels;
  char		**cmd;
  void		(*cmd_handler)(struct s_server *, s_client *);
}		s_server;

typedef void	(*cmd_handler)(s_server *, s_client *);

void		exec_server(s_server *, s_client *);
void		exec_nick(s_server *, s_client *);
void		exec_list(s_server *, s_client *);
void		exec_join(s_server *, s_client *);
void		exec_part(s_server *, s_client *);
void		exec_users(s_server *, s_client *);
void		exec_names(s_server *, s_client *);
void		exec_msg(s_server *, s_client *);
void		exec_accept_file(s_server *, s_client *);

#endif		/* !S_SERVER_H_ */
