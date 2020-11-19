/*
** command.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu May 18 17:49:19 2017 Gabriel Forteville
** Last update Sun May 21 20:47:21 2017 Gabriel Forteville
*/

#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	"execcommand.h"
#include	"client.h"

void		log_user(char **command, struct s_client *client)
{
  if (client->log == NOLOG && strcmp(command[0], "USER") == 0)
    {
      if (command[1] != NULL && strcmp(command[1], "Anonymous") == 0)
	{
	  client->log = NEEDPASSWORD;
	  write(client->fd, "331 User name is OK, need password.\r\n", 37);
	}
      else
	write(client->fd, "530 Wrong user name.\r\n", 22);
    }
  if (client->log == NEEDPASSWORD && strncmp(command[0], "PASS", 5) == 0)
    {
      client->log = LOG;
      write(client->fd, "230 User logged in, proceed.\r\n", 30);
    }
}

int		parse_command(char **command, struct s_client *client)
{
  if (command == NULL || command[0] == NULL)
    return 0;
  if (client->log != LOG && strcmp(command[0], "QUIT") != 0)
    {
      if (client->log == NOLOG && strcmp(command[0], "USER") != 0)
	write(client->fd, "332 You can only do\
QUIT when you are not loggin.\r\n", 51);
      else if (client->log == NEEDPASSWORD && strcmp(command[0], "PASS") != 0)
	write(client->fd, "330 User name is OK, need password.\r\n", 37);
      else
	log_user(command, client);
      return 0;
    }
  if (strcmp(command[0], "QUIT") == 0)
    return 1;
  return exec_command(command, client);
}
