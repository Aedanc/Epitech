/*
** server.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 21:16:25 2017 Gabriel Forteville
** Last update mer. juin 7 21:16:25 2017 Gabriel Forteville
*/

#include		<netinet/in.h>
#include		<sys/socket.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		<arpa/inet.h>
#include		<stdio.h>
#include		<netdb.h>
#include		<string.h>
#include		<stdlib.h>
#include		<errno.h>
#include		"client/structClient.h"

void			setClientData(char **command, t_client *client)
{
  struct protoent	*pe;
  int			i;

  i = 0;
  pe = getprotobyname("TCP");
  if (!pe)
    return ;
  client->server.fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  while (command[1][i] != 0 && command[1][i] != ':')
    i++;
  client->server.ip = strndup(command[1], i);
  if (command[1][i] == ':')
    client->server.port = atoi(command[1] + i + 1);
  else
    client->server.port = 21;
}

int			server(char **command, t_client *client)
{
  struct sockaddr_in	s_in;

  if (command[1] == NULL || command[2] != NULL)
    {
      printf("@Console: use: /server $host:[$port]\n");
      return (0);
    }
  setClientData(command, client);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->server.port);
  s_in.sin_addr.s_addr = inet_addr(client->server.ip);
  if (connect(client->server.fd, (struct sockaddr *)&s_in, sizeof(s_in)) == - 1)
    {
      close(client->server.fd);
      printf("@Console: %s\n", strerror(errno));
    }
  else
    printf("@console: You are now connect to %s on the port %i with the name"
		   " %s\n", client->server.ip, client->server.port
	    , client->nickname);
  return (0);
}
