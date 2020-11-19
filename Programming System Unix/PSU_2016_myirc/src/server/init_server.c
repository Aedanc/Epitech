/*
** init_server.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 18:01:11 2017 Pauline Maes
** Last update Sun Jun 11 19:12:19 2017 Pauline Maes
*/

#include	<stdlib.h>
#include	<string.h>
#include	"init_server.h"

static char	**init_cmd(int fd)
{
  char		**ret;

  if ((ret = malloc(sizeof(char *) * 9)) == NULL)
    {
      manage_error("Error: cannot create server\n", fd);
      return (NULL);
    }
  ret[0] = strdup("server");
  ret[1] = strdup("nick");
  ret[2] = strdup("list");
  ret[3] = strdup("join");
  ret[4] = strdup("part");
  ret[5] = strdup("users");
  ret[6] = strdup("name");
  ret[7] = strdup("accept_file");
  ret[8] = NULL;
  return (ret);
}

static void	init_handler(cmd_handler *tab)
{
  tab[0] = &exec_server;
  tab[1] = &exec_nick;
  tab[2] = &exec_list;
  tab[3] = &exec_join;
  tab[4] = &exec_part;
  tab[5] = &exec_users;
  tab[6] = &exec_names;
  tab[7] = &exec_msg;
  tab[8] = &exec_accept_file;
}

s_server	*init_server(int port, int fd)
{
  s_server	*ret;

  if ((ret = malloc(sizeof(s_server))) == NULL)
    {
      manage_error("Error: cannot create server\n", fd);
      return (NULL);
    }
  ret->port = port;
  ret->fd = fd;
  FD_ZERO(&(ret->readfds));
  ret->channels = NULL;
  ret->cmd = init_cmd(fd);
  if ((ret->cmd_handler = malloc(sizeof(cmd_handler) * 9)) == NULL)
    {
      manage_error("Error: cannot create server\n", fd);
      return (NULL);
    }
  init_handler(&(ret->cmd_handler));
  return (ret);
}
