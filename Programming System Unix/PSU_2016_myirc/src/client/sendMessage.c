/*
** sendMessage.c for  in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  dim. juin 11 15:5:9 2017 Gabriel Forteville
** Last update dim. juin 11 15:5:9 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	<string.h>
#include	"client/structClient.h"

void		sendMessage(t_client *client, char *line, ssize_t lenLine)
{
  line[lenLine] = 0;
  write(client->server.fd, client->nickname, strlen(client->nickname));
  write(client->server.fd, " ", 1);
  write(client->server.fd, line, (size_t)lenLine);
}