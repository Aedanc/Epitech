/*
** my.h for my.h in /home/baldas/libmy/new_lib
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Wed Jan 13 17:49:28 2016 baldas
** Last update Thu Mar 17 16:52:04 2016 Hugo Baldassin
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcpy(char *str);
char	*my_strcat(char *dest, char *src);

int	my_put_nbr(int nb);
int	my_put_nbr_base(int nb);
int	my_getnbr(char *str);
int	my_nblen(int nb);

int	my_str_isnum(char *str);
int	my_str_isalpha(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);

int	my_tablen(char **tab);
char	**my_str_to_wordtab(char *str);
int	my_show_wordtab(char **tab);
void	free_tab(char **tab);

#endif /* MY_H_ */
