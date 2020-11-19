/*
** dele.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 19:48:48 2017 Gabriel Forteville
** Last update Fri May 26 10:15:35 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	<limits.h>
#include	<stdlib.h>
#include	"string.h"
#include	"client.h"
#include	"init.h"

int		countchar(char *str, char c)
{
  int		i;
  int		nbrc;

  nbrc = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	nbrc++;
      i++;
    }
  return (nbrc);
}

int		dele(char **command, struct s_client *client)
{
  char		*tmp1;
  char		*newPath;

  newPath = NULL;
  if (command[1] == (tmp1 = NULL))
    write(client->fd, "501 syntax error\n\r.", 19);
  else
    {
      if (command[1][0] == '/')
	init_path(newPath, command[1], client);
      else
	newPath = strdup(command[1]);
      tmp1 = realpath(newPath, tmp1);
      if (countchar(tmp1, '/') <= countchar(client->realPath, '/'))
	write(client->fd, "553 access denied.\r\n", 22);
      else
	{
	  if (remove(tmp1) == -1)
	    write(client->fd, "553 Directory not empty\n\r", 25);
	  write(client->fd, "250 Requested file action okay, completed.\r\n",
		44);
	  free(tmp1);
	}
    }
  return (0);
}
