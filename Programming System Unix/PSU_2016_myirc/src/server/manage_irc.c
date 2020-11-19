/*
** manage_irc.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu Jun  8 18:16:46 2017 Pauline Maes
** Last update Sun Jun 11 23:29:21 2017 Pauline Maes
*/

#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdio.h>
#include	        "manage_irc.h"

int			manage_irc(s_server *server)
{
  int			ret;
  int			user;
  fd_set	        readfds;
  s_client		*list_client;

  ret = 0;
  user = 0;
  list_client = NULL;
  FD_ZERO(&readfds);
  while (42)
    {
      if (select(max_fd(list_client), &readfds, NULL, NULL, NULL) == -1)
	return (84);
      watch_sockets(&readfds, list_client, server, user);
    }
  return (ret);
}
