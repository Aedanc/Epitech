/*
** command.h for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 20 18:27:16 2017 Gabriel Forteville
** Last update Sun May 21 20:54:43 2017 Gabriel Forteville
*/

#ifndef _COMMAND_H_
# define _COMMAND_H_

# include	"client.h"

int		parse_command(char **command, struct s_client *client);

#endif	/* !_COMMAND_H_ */
