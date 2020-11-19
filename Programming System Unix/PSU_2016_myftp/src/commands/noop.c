/*
** noop.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 19:32:25 2017 Gabriel Forteville
** Last update Sun May 21 19:41:12 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	"client.h"

int		noop(char **command, struct s_client *client)
{
  (void)command;
  write(client->fd, "200 NOOP ok.\r\n", 14);
  return 0;
}
