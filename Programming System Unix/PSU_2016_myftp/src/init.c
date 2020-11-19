/*
** init.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 13 16:48:21 2017 Gabriel Forteville
** Last update Sun May 21 20:48:11 2017 Gabriel Forteville
*/

#include		<netdb.h>
#include		<stdlib.h>
#include		<string.h>
#include		<stdbool.h>
#include		"client.h"
#include		"error.h"

void			init_path(char *path, char *command, struct s_client *client)
{
  path = strdup(client->realPath);
  path = realloc(path, strlen(path) + strlen(command) + 1);
  strcat(path, command);
}

void			init_sockaddr(struct sockaddr_in *s_in, int port)
{
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
}

struct s_client		init_client(char *path)
{
  struct s_client	client;

  client.size = sizeof(client.s_in);
  client.realPath = strdup(path);
  client.path = strdup("/");
  client.log = NOLOG;
  return client;
}

int			init_socket(int port)
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  int			fd;

  pe = getprotobyname("TCP");
  if (pe == NULL)
    return put_error("getprotobyname");
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return put_error("socket");
  init_sockaddr(&s_in, port);
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return close_error(fd, "bind");
  if (listen(fd, 128) == -1)
    return close_error(fd, "listen");
  return (fd);
}
