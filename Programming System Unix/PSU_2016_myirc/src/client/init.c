/*
** init.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 14:12:4 2017 Gabriel Forteville
** Last update mer. juin 7 14:12:4 2017 Gabriel Forteville
*/

#include <string.h>
#include "client/structClient.h"

void	initClient(t_client *client)
{
  client->server.ip = NULL;
  client->server.port = 0;
  client->server.chanel = NULL;
  client->nickname = strdup("Anonymous");
  client->quit = 1;
  client->server.fd = -1;
}
