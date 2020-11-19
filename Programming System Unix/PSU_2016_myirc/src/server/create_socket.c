/*
** create_socket.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Mon Jun  5 18:50:06 2017 Pauline Maes
** Last update Mon Jun  5 19:00:33 2017 Pauline Maes
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"create_socket.h"

static int		bind_socket(int fd, int port)
{
  int			ret;
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  ret = bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in));
  if (ret == -1)
    {
      manage_error("Error: could not bind socket\n", fd);
      return (ret);
    }
  ret = listen(fd, 128);
  if (ret == -1)
    {
      manage_error("Error: could not mark socket\n", fd);
      return (ret);
    }
  return (0);
}

int			create_socket(int port)
{
  int			fd;
  int			ret;
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  if (!pe)
    {
      fprintf(stderr, "Error: could not get protocol\n");
      return (-1);
    }
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    {
      fprintf(stderr, "Error: could not create socket\n");
      return (-1);
    }
  ret = bind_socket(fd, port);
  if (ret == -1)
    return (ret);
  return (fd);
}
