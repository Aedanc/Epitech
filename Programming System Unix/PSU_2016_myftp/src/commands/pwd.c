/*
** pwd.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 20 22:08:45 2017 Gabriel Forteville
** Last update Sun May 21 20:51:18 2017 Gabriel Forteville
*/

#include	<string.h>
#include	<unistd.h>
#include	"client.h"

int		pwd(char **command, struct s_client *client)
{
  (void)command;
  write(client->fd, "257 ", 4);
  write(client->fd, client->path, strlen(client->path));
  write(client->fd, "\r\n", 2);
  return 0;
}
