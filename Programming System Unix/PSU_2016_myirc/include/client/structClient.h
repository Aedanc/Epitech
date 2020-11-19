/*
** structClient.h for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 14:14:52 2017 Gabriel Forteville
** Last update mer. juin 7 14:14:52 2017 Gabriel Forteville
*/

#ifndef _STRUCTCLIENT_H_
# define _STRUCTCLIENT_H_

# include <zconf.h>

typedef struct		s_fds
{
  int		actfd;
  int		ret;
  int		fdmax;
  fd_set	*read_fds;
}			t_fds;


typedef struct 		s_server
{
  char			*ip;
  int			port;
  char			*chanel;
  int			fd;
}			t_server;

typedef struct		s_client
{
  t_server		server;
  char 			*nickname;
  int 			quit;
}			t_client;

#endif /* !_STRUCTCLIENT_H_ */
