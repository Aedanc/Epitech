/*
** main.h for projTester in /home/fortevg/rendu/projTester/include
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 22 12:28:58 2016 Forteville Gabriel
** Last update Fri Jun 24 21:51:34 2016 Forteville Gabriel
*/

#include	"dirent.h"

#ifndef		_MAIN_H_
# define	_MAIN_H_

DIR	 	*parsing(int ac, char **av);

void		print_dir(char *path);

void		alphabe_tree(DIR *stack, int nbr_stack);

void		argment(char *name_dir, DIR *stack, char *command);

#endif		/* !_MAIN_H_ */
