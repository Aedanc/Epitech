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

# include	"client.h"

int		pwd(char **, struct s_client *);

int		cwd(char **, struct s_client *);

int		cdup(char **, struct s_client *);

int		help(char **, struct s_client *);

int		noop(char **, struct s_client *);

int		dele(char **, struct s_client *);

typedef int	(*fonction)(char **command, struct s_client *client);

#endif /* !_FUNCTAB_H_ */
