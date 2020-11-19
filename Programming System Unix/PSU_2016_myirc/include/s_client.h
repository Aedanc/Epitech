/*
** s_client.h for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu Jun  8 18:23:40 2017 Pauline Maes
** Last update Thu Jun  8 19:02:36 2017 Pauline Maes
*/

#ifndef			S_CLIENT_H_
# define		S_CLIENT_H_

typedef struct		s_client
{
  int			fd;
  int			host;
  int			port;
  char			*nickname;
  char			*channel;
  struct s_client	*next;
}			s_client;

#endif			/* !S_CLIENT_H_ */
