/*
** my_cmd_tab.c for my_cmd_tab in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Thu Mar 17 14:26:06 2016 Hugo Baldassin
** Last update Sat Mar 26 22:38:47 2016 vermeu_v
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"
#include	"asm.h"

void		put_chars(char **tab, char *str, int words)
{
  int		i;
  int		j;
  int		y;
  int		lim;
  char		separator;

  i = 0;
  y = 0;
  lim = (first_word_label(str)) ? 2 : 1;
  separator = ' ';
  while (y < words)
    {
      j = 0;
      while (str[i] == separator)
	i++;
      while (str[i] != separator && str[i] != '\0')
	tab[y][j++] = str[i++];
      tab[y][j] = '\0';
      y++;
      if (y == lim)
	separator = SEPARATOR_CHAR;
    }
}

void		malloc_setup(char **tab, char *str, int words)
{
  int		y;
  int		tmp;
  int		i;
  int		lim;
  char		separator;

  y = 0;
  i = 0;
  lim = (first_word_label(str)) ? 2 : 1;
  separator = ' ';
  while (y < words)
    {
      while (str[i] == separator)
	i++;
      tmp = i;
      while (str[i] != separator && str[i] != '\0')
	i++;
      if (!(tab[y++] = malloc((i - tmp + 1) * sizeof(char))))
	error_displays(-7, 0);
      if (y == lim)
	separator = SEPARATOR_CHAR;
    }
}

int		count_args(char *str)
{
  int		i;
  int		count;
  int		lim;
  char		separator;

  i = 0;
  count = 0;
  lim = (first_word_label(str)) ? 2 : 1;
  separator = ' ';
  while (str[i] != '\0')
    {
      while (str[i] == separator)
	i++;
      while (str[i] != separator && (str[i] != '\0'))
	i++;
      if (str[i - 1] != separator)
	count++;
      if (count == lim)
	separator = SEPARATOR_CHAR;
    }
  return (count);
}

char		**my_cmd_tab(char *line)
{
  char		**tab;
  int		words;

  words = count_args(line);
  if (!(tab = malloc((words + 1) * sizeof(char *))))
    error_displays(-7, 0);
  tab[words] = NULL;
  if (words != 0)
    {
      malloc_setup(tab, line, words);
      put_chars(tab, line, words);
      epur_tab(tab);
    }
  return (tab);
}
