/*
** resource.h for  in /home/fortevg/rendu/CPE/CPE_2015_Allum1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Feb 17 17:23:07 2016 Forteville Gabriel
** Last update Wed Feb 17 17:29:28 2016 Forteville Gabriel
*/

# ifndef	_LIB_H_
# define	_LIB_H_

int	my_get_nbr(char *str, int i);

void	my_putchar(char c);

int	my_put_nbr(int nb);

int	my_put_nbr_base(int nb, char *base);

void	my_putstr(char *str);

int	my_show_word_tab(char **str);

int	my_strcompare(char *str1, char *str2);

char	*my_strcpy(char *src, char *goal, int start, int end);

int	my_strlen(char *str);

char	**my_str_to_word_tab(char *str, char c);

# endif		/*_LIB_H_*/
