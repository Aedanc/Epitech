/*
** my.h for libmy in /home/fortev_g/rendu/
** 
** Made by Gabriel Forteville
** Login   <willau_h@epitech.net>
**
** Started on  Thu Oct  8 02:11 2015 Gabriel Forteville
** Last update Thu Nov  5 09:50:40 2015 Gabriel Forteville
*/
#ifndef MY_H_
#define MY_H_

void	my_putchar(char c);

int	my_isneg(int nb);

int	my_put_nbr(int nb);

int	my_swap (int *a, int *b);

int	my_putstr(char *str);

int	my_strlen(char *str);

int	my_getnbr(char *str);

int	my_power_rec(int nb, int power);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

int	my_is_prime_sup(int nb);

char	*my_strcpy(char *dest, char *to_find);

char	*my_strncpy(char *dest, char *src, int nb);

char	*my_revstr(char *str);

char	*my_strstr(char *s1, char *s2);

int	my_strcmp(char *s1, char *s2);

int	my_strncmp(char *s1, char *s2, int nb);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcat(char *dest, char *src);

char	*my_strncat(char *dest, char *src, int nb);

#endif
