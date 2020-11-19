/*
** basic.h for  in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 12:45:37 2016 Gabriel Forteville
** Last update Mon Jun 13 19:39:03 2016 Forteville Gabriel
*/

#ifndef		_BASIC_H_
# define	_BASIC_H_

int		my_strlen(char *str);

int		my_putstr(int fd,
			  char *str);

int		my_strncmp(const char *s1,
			   const char *s2,
			   int start,
			   int end);

char		**my_str_to_wordtab(char *str,
				    char *separator);

void		free_tab(char **tab);

#endif		/* _BASIC_H_ */
