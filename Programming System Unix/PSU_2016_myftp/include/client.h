/*
** client.h for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Fri May 12 16:41:19 2017 Gabriel Forteville
** Last update Sun May 21 20:54:07 2017 Gabriel Forteville
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

# include		<netdb.h>
# include		<stdio.h>
# include		<stdbool.h>

enum			e_logStatus {
  NOLOG,
  NEEDPASSWORD,
  LOG
};

struct			s_client
{
  struct sockaddr_in	s_in;
  socklen_t		size;
  int			fd;
  FILE			*Fp;
  char			*ip;
  char			*realPath;
  char			*path;
  enum e_logStatus	log;
};

#endif /* _CLIENT_H_*/
