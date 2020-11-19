/*
** max_fd.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 21:54:17 2017 Pauline Maes
** Last update Sun Jun 11 23:20:16 2017 Pauline Maes
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	"s_client.h"

int		max_fd(s_client *client)
{
  int		max;
  s_client	*tmp;

  max = 3;
  tmp = client;
  while (tmp != NULL)
    {
      if ((tmp->fd + 1) > max)
	max = tmp->fd + 1;
      tmp = tmp->next;
    }
  return (max);
}
