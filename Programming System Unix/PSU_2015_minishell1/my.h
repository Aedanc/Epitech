/*
** my.h for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Dec  7 17:34:09 2015 Forteville Gabriel
** Last update Mon Jan 25 18:13:59 2016 Forteville Gabriel
*/

# ifndef MY_H_
# define MY_H_

void		my_putchar(char c);

int		my_strlen(char *str);

int		my_putstr(char *str);

void		doshell(char **userinput, char **env);

int		my_strcompare(char *str1, char *str2, int i);

int		my_get_nbr(char *str, int i);

char		**my_str_to_word_tab(char *str, char c);

int		my_show_word_tab(char **str);

char		*my_strcpy(char *src, int start, int end);

char		*my_struni(char *str1, char *str2);

# endif
