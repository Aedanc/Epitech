/*
** main.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp/src
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu May 11 11:41:22 2017 Gabriel Forteville
** Last update Sun May 21 20:56:03 2017 Gabriel Forteville
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<arpa/inet.h>
#include		<dirent.h>
#include		"command.h"
#include		"execcommand.h"
#include		"strtowordtab.h"
#include		"error.h"
#include		"tools.h"
#include		"init.h"

int			handle_client(int fd, struct s_client *client)
{
  char			**command;

  if (client->fd == -1)
    return close_error(fd, "accept");
  client->ip = inet_ntoa(client->s_in.sin_addr);
  printf("ip client: %s\n", client->ip);
  write(client->fd, "220 (myFtp v0.9)\r\n", 18);
  command = get_command(client);
  while (parse_command(command, client) == 0)
    {
      free_tab(command);
      command = get_command(client);
      if (command == NULL)
	return (-1);
    }
  write(client->fd, "221 Bye!\r\n", 10);
  if (close(client->fd) != 0)
    return put_error("close");
  exit(0);
}

int			connectionClient(int fd, char *path)
{
  int			pid;
  struct s_client	client;

  client = init_client(path);
  while (1)
    {
      client.fd = accept(fd, (struct sockaddr *)&(client.s_in),
			 &(client.size));
      pid = fork();
      if (pid == -1)
	return close_error(fd, "fork");
      if (pid == 0)
	handle_client(fd, &client);
    }
  if (close(fd) == -1)
    return put_error("close");
  return 0;
}

int			main(int ac, char **av)
{
  int			fd;
  char			realPath[PATH_MAX];
  DIR			*path;

  if (ac != 3 || !is_num(av[1]))
    {
      fprintf(stdout, "Usage : ./server port path\n");
      return (-1);
    }
  path = opendir(av[2]);
  if (path == NULL)
    {
      put_error("path");
      return 1;
    }
  closedir(path);
  fd = init_socket(atoi(av[1]));
  if (fd == -1)
    return (1);
  return (connectionClient(fd, realpath(av[2], realPath)));
}
