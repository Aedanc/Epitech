/*
** help.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 19:16:27 2017 Gabriel Forteville
** Last update Sun May 21 20:53:16 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	"client.h"

int		help(char **command, struct s_client *client)
{
  (void)command;
  write(client->fd, "214-The following commands are recognized.\r\n\
USER PASS CWD CDUP QUIT DELE PWD HELP NOOP\r\n\
214 Help OK.\n\r", 102);
  return 0;
}
