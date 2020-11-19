/*
** cwd.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 16:37:45 2017 Gabriel Forteville
** Last update Sun May 21 20:26:11 2017 Gabriel Forteville
*/

#include	<limits.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"client.h"
#include	"error.h"
#include	"init.h"

int		cwd(char **command, struct s_client *client)
{
  char		*tmpPath;
  char		*newPath;

  if (command[1] == NULL && write(client->fd, "501 path needed\r\n", 17) != -1)
    return 0;
  newPath = NULL;
  tmpPath = strdup(command[1]);
  if (command[1][0] == '/')
    init_path(tmpPath, command[1], client);
  newPath = realpath(tmpPath, newPath);
  if (newPath == NULL || strlen(newPath) < strlen(client->realPath)
      || chdir(newPath) != 0)
    write(client->fd, "553 Wrong path.\r\n", 17);
  else
    {
      free(client->path);
      client->path = strdup(&newPath[strlen(client->realPath)]);
      client->path = realloc(client->path, strlen(client->path) + 3);
      client->path = strcat(client->path, "/");
      write(client->fd, "250 success.\r\n", 14);
    }
  free(tmpPath);
  free(newPath);
  return 0;
}
