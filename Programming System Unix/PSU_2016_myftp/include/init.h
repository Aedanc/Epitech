/*
** init.h for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 13 16:54:18 2017 Gabriel Forteville
** Last update Sun May 21 20:54:32 2017 Gabriel Forteville
*/

#ifndef _INIT_H_
# define _INIT_H_

# include		<netdb.h>

void			init_path(char *path, char *command, struct s_client *client);

void			init_sockaddr(struct sockaddr_in *s_in, int port);

int			init_socket(int port);

struct s_client		init_client(char *path);

#endif /* !_INIT_H_ */
