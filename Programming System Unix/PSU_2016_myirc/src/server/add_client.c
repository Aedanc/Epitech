/*
** add_client.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Fri Jun  9 13:57:43 2017 Pauline Maes
** Last update Sun Jun 11 23:37:21 2017 Pauline Maes
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_client.h"
#include	"s_server.h"

static int	len_user(int nb)
{
  int		len;

  len = 1;
  while (nb / 10 > 10)
    {
      nb = nb / 10;
      len++;
    }
  return (len);
}

static char	*init_nickname(int nb)
{
  int		len_num;
  char		*init;

  len_num = len_user(nb);
  init = malloc(sizeof(char) * (4 + len_num + 1));
  if (init == NULL)
    return (NULL);
  sprintf(init, "user%d", nb);
  return (init);
}

static s_client	assign_client(s_client client, int user, s_server *server)
{
  client.host = 0;
  client.port = 0;
  client.nickname = init_nickname(user);
  client.channel = NULL;
  client.next = NULL;
  if (server)
    FD_SET(client.fd, &(server->readfds));
  return (client);
}

static void	send_welcome(int fd, char *nick)
{
  dprintf(fd, "001 %s:Welcome to the Internet Relay Network %s!\r\n", nick,
	  nick);
  dprintf(fd, "002 %s:Your host is myirc, running version 0.1!\r\n", nick);
  dprintf(fd, "003 %s:This server has been started today\r\n", nick);
}

s_client	*add_client(s_client client, s_server *server, s_client *client_list, int user)
{
  s_client	*tmp;

  client = assign_client(client, user, NULL);
  tmp = client_list;
  if (client_list == NULL)
    {
      tmp = malloc(sizeof(s_client));
      if (tmp == NULL)
	return (NULL);
      *tmp = assign_client(client, user, server);
      send_welcome(client.fd, client.nickname);
      return (tmp);
    }
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = malloc(sizeof(s_client));
  if (tmp->next == NULL)
    return (NULL);
  *(tmp->next) = assign_client(client, user, server);
  send_welcome(client);
  return (client_list);
}
