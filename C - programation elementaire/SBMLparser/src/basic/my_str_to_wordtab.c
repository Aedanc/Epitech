/*
** requirement.c for  in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 9:10:03 2016 Gabriel Forteville
** Last update Wed Jun 15 13:10:39 2016 Forteville Gabriel
*/

#include <unistd.h>
#include <stdlib.h>

static int		is_separator(char c, char *str)
{
  int			index;

  index = 0;
  while (str[index] != 0)
    {
      if (c == str[index])
	return (0);
      index++;
    }
  return (1);
}

static char		**mallocword(char *str, char **wordtab, char *separator)
{
  int		index;
  int		tmp;
  int		tab;

  tab = 0;
  index = 0;
  while (is_separator(str[index], separator) == 0)
    index++;
  while (str[index] != 0)
    {
      tmp = index;
      while (is_separator(str[index], separator) != 0 && str[index] != 0)
	index++;
      if ((wordtab[tab] = malloc(sizeof(char) * (index - tmp + 1))) == NULL)
	return (NULL);
      wordtab[tab][index - tmp] = 0;
      tab++;
      while (is_separator(str[index], separator) == 0 && str[index] != 0)
	index++;
    }
  return (wordtab);
}

static char		**malloctab(char *str, char *separator)
{
  int		index;
  int		nbr_tab;
  char		**wordtab;

  index = 0;
  while (is_separator(str[index], separator) == 0)
    index++;
  nbr_tab = 0;
  while (str[index++] != 0)
    {
      if ((is_separator(str[index], separator) == 0 &&
	   is_separator(str[index - 1], separator) != 0 && str[index + 1]) != 0)
	nbr_tab++;
    }
  if ((wordtab = malloc(sizeof(char *) * (nbr_tab + 2))) == NULL)
    return (NULL);
  wordtab[nbr_tab] = NULL;
  wordtab[nbr_tab + 1] = NULL;
  return (wordtab);
}

char		**my_str_to_wordtab(char *str, char *separator)
{
  int		word;
  int		tab;
  int		index;
  char		**wordtab;

  tab = 0;
  index = 0;
  if (str == NULL || (wordtab = malloctab(str, separator)) == NULL ||
      (wordtab = mallocword(str, wordtab, separator)) == NULL)
    return (NULL);
  while (str[index] != 0)
    {
      word = 0;
      while (is_separator(str[index], separator) == 0 && str[index] != 0)
	index++;
      while (is_separator(str[index], separator) != 0 && str[index] != 0)
	{
	  wordtab[tab][word] = str[index];
	  index++;
	  word++;
	}
      tab++;
    }
  return (wordtab);
}
