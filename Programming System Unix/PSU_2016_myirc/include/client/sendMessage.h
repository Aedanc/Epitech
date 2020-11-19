/*
** sendMessage.h for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  dim. juin 11 20:9:25 2017 Gabriel Forteville
** Last update dim. juin 11 20:9:25 2017 Gabriel Forteville
*/

#ifndef _SENDMESSAGE_H
# define _SENDMESSAGE_H

# include	"client/structClient.h"

void		sendMessage(t_client *client, char *line, ssize_t lenLine);

#endif /* !_SENDMESSAGE_H_ */
