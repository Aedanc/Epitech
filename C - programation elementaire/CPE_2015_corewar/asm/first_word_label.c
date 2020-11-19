/*
** first_word_label.c for first_word_label in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Mar 23 19:10:56 2016 Hugo Baldassin
** Last update Thu Mar 24 19:13:03 2016 Hugo Baldassin
*/

#include	"op.h"
#include	"asm.h"
#include	"my.h"

int		first_word_label(char *line)
{
  int		i;

  i = 0;
  while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
    i++;
  if (line[i] == '\0' || my_strlen(line) == 1)
    return (0);
  while (line[i] != LABEL_CHAR && line[i] != '\0')
    {
      if (is_a_label_char(line[i]) == 0)
	return (0);
      if ((my_strlen(line) - i) >= 2)
	if (line[i + 1] == ' ' && line[i + 2] == LABEL_CHAR &&
	    (line[i + 3] == ' ' || line[i + 3] == ' '))
	  {
	    line[i + 1] = LABEL_CHAR;
	    line[i + 2] = ' ';
	  }
      i++;
    }
  if (line[i] == LABEL_CHAR && (line[i + 1] == ' ' || line[i + 1] == '\0'))
    return (1);
  return (0);
}
