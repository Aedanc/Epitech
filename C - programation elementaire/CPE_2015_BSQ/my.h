/*
** my.h for  in /home/fortevg/rendu/CPE/CPE_2015_BSQ
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec 15 14:46:17 2015 Forteville Gabriel
** Last update Sat Dec 19 23:24:30 2015 Forteville Gabriel
*/

#ifndef MY_H_
#define MY_H_

typedef struct s_list
{
  int		x;
  int		y;
  int		lenghtmap;
  int		size;
  int		sizemax;
  int		xmax;
  int		ymax;
}		t_list;

int	my_getnbr(char *str);
char	**now_find_the_square(t_list *square, char **map, int nbrline);
int	my_intlen(int nbr);
void	now_put_the_square(t_list *square, char **map);

#endif
