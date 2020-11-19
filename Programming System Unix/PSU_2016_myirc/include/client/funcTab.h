/*
** functab.h for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 20 22:00:37 2017 Gabriel Forteville
** Last update Sun May 21 19:59:37 2017 Gabriel Forteville
*/

#ifndef _FUNCTAB_H_
# define _FUNCTAB_H_

# include	"client/structClient.h"

int		quit(char **, struct s_client *);

int		nick(char **, struct s_client *);

int		help(char **, struct s_client *);

int		server(char **, struct s_client *);

typedef int	(*fonction)(char **command, t_client *client);

#endif /* !_FUNCTAB_H_ */
