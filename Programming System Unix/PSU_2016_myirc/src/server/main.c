/*
** main.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu May 25 16:12:55 2017 Pauline Maes
** Last update Sun Jun 11 22:47:38 2017 Pauline Maes
*/

#include	<unistd.h>
#include	"main_server.h"

int		main(int ac, char **av)
{
  int		ret;
  int		port;
  int		fd;
  s_server	*server;

  if ((ret = check_args(ac, av, &port)) != 1)
    return (ret);
  fd = create_socket(port);
  if (fd == -1)
    return (84);
  server = init_server(port, fd);
  if (server == NULL)
    return (84);
  ret = manage_irc(server);
  return (ret);
}
