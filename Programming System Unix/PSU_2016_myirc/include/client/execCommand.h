/*
** execCmmand.h for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 15:30:30 2017 Gabriel Forteville
** Last update mer. juin 7 15:30:30 2017 Gabriel Forteville
*/

#ifndef _EXECCMMAND_H_
# define _EXECCMMAND_H_

# include	"client/structClient.h"

void		execCommand(t_client *client, char *command, ssize_t lenCommand);

#endif /* !_EXECCMMAND_H_ */
