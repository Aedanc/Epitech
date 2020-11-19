/*
** get_next_line.h for  in /home/hurlu/rendu/CPE_2015_getnextline
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Mon Jan  4 09:59:33 2016 Hugo Willaume
** Last update Wed Jan 13 15:11:22 2016 Hugo Willaume
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# ifndef	READ_SIZE
#  define	READ_SIZE (5)
# endif		/* READ_SIZE */

void	init_str(char *str, int size);

char	*my_re_alloc(char *result, int *malloc_size);

int	init_all(char **buf, char **result, int *y, int *malloc_size);

int	check_buf(char *buf, int *i, int fd, int *end);

char	*get_next_line(const int fd);

#endif		/* GET_NEXT_LINE_H_ */
