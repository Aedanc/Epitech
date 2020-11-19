/*
** basics.h for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 16:58:36 2016 Hugo Willaume
** Last update Fri Mar 25 19:05:27 2016 Hugo Willaume
*/

#ifndef		BASICS_H
# define	BASICS_H

int	my_getnbr(char *);

void	my_putchar(char);

void	my_putstr(char *);

int	my_strcmp(char *, char *);

int	my_strncmp(char *, char *, int);

int	my_strlen(char *);

int	my_putnbr(int);

char	*my_realloc(char *, int);

char	*my_strdup(char *);

char	*my_str_append(char *, char *);

char	*my_calloc(int);

void	init_char_array(char *, int);

void	init_int_array(int *, int);

int	is_not_in_i(int *, int, int);

void	my_putnbrhex(int nb);

void	my_putnbrhexspe(int, char *);
#endif		/* BASICS_H */
