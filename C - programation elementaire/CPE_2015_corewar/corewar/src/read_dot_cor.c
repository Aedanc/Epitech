/*
** read_dot_cor.c for  in /home/hurlu/rendu/CPE_2015_corewar
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 18:51:21 2016 Hugo Willaume
** Last update Sun Mar 27 05:36:41 2016 Hugo Willaume
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"basics.h"
#include	"virtual.h"

static int	organize_cor_info(int fd, t_header **head)
{
  *head = malloc(sizeof(t_header));
  read(fd, (*head), sizeof(t_header));
  (*head)->magic = big_endian((*head)->magic);
  (*head)->prog_size = big_endian((*head)->prog_size);
  if (((*head)->magic) != COREWAR_EXEC_MAGIC)
    return (21);
  return (0);
}

int	check_cor(char *name)
{
  int	i;

  i = my_strlen(name);
  while (name[--i] != '.');
  if (my_strcmp(".cor", &name[i]) != 0)
    return (1);
  return (0);
}

void	init_standards(t_champions *champ)
{
  champ->ch_nb = 0;
  champ->start_address = -1;
  champ->live = 0;
}

void		put_champ_in_list(t_champions **champ)
{
  t_champions	*tmp;

  if (*champ == NULL)
    {
      (*champ) = malloc(sizeof(t_champions));
      (*champ)->next = NULL;
    }
  else
    {
      tmp = *champ;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = malloc(sizeof(t_champions));
      tmp = tmp->next;
      tmp->next = NULL;
    }
}

int		read_cor_file(char *name, t_champions **champ)
{
  int		fd;
  int		err;
  t_champions	*tmp;
  t_header	*head;

  if (check_cor(name) != 0)
    return (2);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (2);
  put_champ_in_list(champ);
  tmp = *champ;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((err = organize_cor_info(fd, &head)) != 0)
    return (err);
  tmp->header = head;
  tmp->bytecode = malloc(sizeof(char) * (tmp->header->prog_size + 1));
  read(fd, tmp->bytecode, tmp->header->prog_size);
  tmp->bytecode[tmp->header->prog_size] = '\0';
  close(fd);
  init_standards(tmp);
  return (0);
}
