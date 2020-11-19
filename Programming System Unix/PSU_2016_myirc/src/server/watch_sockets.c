/*
** watch_sockets.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 21:52:39 2017 Pauline Maes
** Last update Sun Jun 11 23:38:53 2017 Pauline Maes
*/

#include		<unistd.h>
#include		<string.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		"watch_sockets.h"

void			new_co(s_client *client_list, s_server *server,
			       int user)
{
  s_client		client;
  struct sockaddr_in	s_in_client;

  client.fd = my_accept(server->fd, &s_in_client);
  if (client.fd != -1)
    client_list = add_client(client, server, client_list, user);
}

void			io_co(s_client *client, s_server *server,
			      fd_set *readfds, s_client *list)
{

  if (FD_ISSET(client->fd, readfds))
    handle_input(client, list, server, readfds);
}

void			watch_sockets(fd_set *readfds, s_client *client,
				      s_server *server, int user)
{
  int			i;
  int			j;
  s_client		*tmp;

  i = 0;
  tmp = client;
  while (i < max_fd(client))
    {
      if (FD_ISSET(i, readfds))
	{
	  if (i == server->fd)
	    new_co(client, server, user);
	  else
	    {
	      j = 0;
	      while (j < i)
		tmp = tmp->next;
	      io_co(tmp, server, readfds, client);
	    }
	}
      i++;
    }
}
