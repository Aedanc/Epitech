/*
** my_accept.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Fri Jun  9 14:13:06 2017 Pauline Maes
** Last update Fri Jun  9 14:16:48 2017 Pauline Maes
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"my_accept.h"

int		my_accept(int fd, struct sockaddr_in *s_in_client)
{
  int		client_fd;
  socklen_t	sin_size;

  sin_size = sizeof(s_in_client);
  client_fd = accept(fd, (struct sockaddr *)s_in_client, &sin_size);
  if (client_fd == -1)
    {
      manage_error("Error: could not accept client\n", fd);
      return (-1);
    }
  return (client_fd);
}
