/*
** epur_line.c for epur_line in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Thu Mar 17 15:31:52 2016 Hugo Baldassin
** Last update Sat Mar 26 23:26:41 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"my.h"

void		epur_comment(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == COMMENT_CHAR)
	{
	  line[i] = '\0';
	  return ;
	}
      i++;
    }
}

void		epur_tabul(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '\t')
	line[i] = ' ';
      i++;
    }
}

char		*epur_line(char *line)
{
  char		*epur;
  int		i;
  int		j;

  epur_comment(line);
  epur_tabul(line);
  if (!(epur = malloc((my_strlen(line) + 1) * sizeof(char))))
    error_displays(-7, 0);
  i = 0;
  j = 0;
  while (line[i] == ' ' && line[i] != '\0')
    i++;
  while (line[i] != '\0')
    {
      while (line[i] == ' ' && (line[i + 1] == ' ' || line[i + 1] == ','))
	i++;
      epur[j++] = line[i++];
    }
  epur[j] = '\0';
  if (j != 0)
    epur[j - 1] = (epur[j - 1] == ' ') ? '\0' : epur[j - 1];
  free(line);
  return (epur);
}
