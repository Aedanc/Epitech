/*
** main.h for SBMLparser in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 12:59:35 2016 Gabriel Forteville
** Last update Wed Jun 15 12:01:44 2016 Forteville Gabriel
*/

#ifndef 	_MAIN_H_
# define 	_MAIN_H_

# include	"struct.h"

int		print_usage();

t_data		*get_data_from_file(const char *path_file);

void		print_in_alpha_order(t_data *info_file);

void		free_linked_list(t_data *info_file);

char		parsing(int ac, char *av[]);

void		 print_species(t_data *info_file);

#endif		/* !_MAIN_H_ */
