/*
** quit.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 16:38:57 2017 Gabriel Forteville
** Last update mer. juin 7 16:38:57 2017 Gabriel Forteville
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"client/structClient.h"

int		quit(char **command, struct s_client *client)
{
  (void)command;
  if (client->server.ip == NULL)
    {
      client->quit = 0;
      printf("Good bye %s!\n", client->nickname);
    }
  else
    {
      printf("@Console: Disconnected of %s on port %i\n", client->server.ip,
	     client->server.port);
      free(client->server.ip);
      client->server.ip = NULL;
      client->server.port = -1;
      close(client->server.fd);
      free(client->server.chanel);
      client->server.chanel = NULL;
      client->quit = 0;
      printf("Good bye %s!\n", client->nickname);
    }
  return (0);
}
