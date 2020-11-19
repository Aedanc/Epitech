/*
** send_reply.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 14:47:14 2017 Pauline Maes
** Last update Sun Jun 11 14:48:47 2017 Pauline Maes
*/

#include	<unistd.h>
#include	<string.h>
#include	"send_reply.h"

int		send_reply(int fd, char *reply)
{
  ssize_t	ret;

  ret = write(fd, reply, strlen(reply));
  if (ret == -1)
    {
      manage_error("Error: could not send reply to client\n", fd);
      return (1);
    }
  return (0);
}
