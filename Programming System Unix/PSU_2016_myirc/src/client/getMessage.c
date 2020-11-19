/*
** getMessage.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  dim. juin 11 20:53:21 2017 Gabriel Forteville
** Last update dim. juin 11 20:53:21 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"client/structClient.h"

void 		getMessage(t_client *client)
{
  char		*tmp;

  tmp = calloc(sizeof(char), 4096);
  read(client->server.fd, tmp, 4096);
  printf("%s", tmp);
  free(tmp);
}