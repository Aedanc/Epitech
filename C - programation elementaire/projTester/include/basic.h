/*
** basic.h for projTester in /home/fortevg/rendu/projTester/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 22 12:34:34 2016 Forteville Gabriel
** Last update Sat Jun 25 16:17:59 2016 Forteville Gabriel
*/

#ifndef		_BASIC_H_
# define	_BASIC_H_

void		error(char *str);

char		*my_path(char *str1, char *str2);

int		my_strlen(char *str);

int		tablen(char **tab);

void		freetab(char **tab);

char		**my_str_to_wordtab(char *str, char *separator);

void		open_file(char *name_file);

#endif		/* !_BASIC_H_ */
