/*
** main.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 13:32:17 2017 Gabriel Forteville
** Last update mer. juin 7 13:32:17 2017 Gabriel Forteville
*/

#include	<stdio.h>
#include	<malloc.h>
#include	<unistd.h>
#include	<zconf.h>
#include	"client/sendMessage.h"
#include	"client/getMessage.h"
#include	"client/execCommand.h"
#include	"client/init.h"

void 		exec(char *line, ssize_t lenLine, t_client *client, t_fds *fds)
{
  while (client->quit != 0)
    {
      fds->actfd = 0;
      FD_ZERO(fds->read_fds);
      (client->server.fd < 0) ? 0 : FD_SET(client->server.fd, fds->read_fds);
      if (FD_SET(0, fds->read_fds), select(fds->fdmax, fds->read_fds, NULL, NULL, NULL) == -1)
	return ;
      while (fds->actfd <= fds->fdmax)
	{
	  if (FD_ISSET(fds->actfd, fds->read_fds))
	    {
		if (fds->actfd == 0)
		  {
		    lenLine = read(0, line, 4096);
	            if (line[0] == '/')
		      execCommand(client, line, lenLine);
		    else
		      sendMessage(client, line, lenLine);
		  }
	      	else
		  getMessage(client);
	    }
	  fds->actfd++;
	}
    }
}

int		main()
{
  char		*line;
  ssize_t	lenLine;
  t_client	client;
  t_fds		fds;
  fd_set	rfds;

  fds.fdmax = 1;
  fds.read_fds = &rfds;
  initClient(&client);
  printf("Hello world! (myIRC client V0.3)\nMax length by line is 4096\n");
  line = calloc(sizeof(char), 4096);
  FD_ZERO(&rfds);
  FD_SET(0, &rfds);
  exec(line, lenLine, &client, &fds);
  free(line);
  free(client.nickname);
  return (0);
}
