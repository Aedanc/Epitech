/*
** basic.h for palindrome in /home/fortevg/rendu/palindrome/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 17:01:30 2016 Forteville Gabriel
** Last update Fri Jun 17 18:17:45 2016 Forteville Gabriel
*/

#ifndef 	_BASIC_H_
# define	_BASIC_H_

# include	"struct.h"

char		*revstr(char *str);

char		*add_str(char *str1, char *str2);

void		find_palindrom(t_data *opt, int cpt);

int		intlen(int nbr);

char		*int_to_str(int nbr);

void		error(char *error, t_data *opt);

#endif		/* !_BASIC_H_ */
