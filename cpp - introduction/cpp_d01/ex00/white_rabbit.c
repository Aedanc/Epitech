/*
** white_rabbit.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01
**
** Made by Forteville Gabriel
** Login   <gabriel.forteville@epitech.net>
**
** Started on  Wed Jan 04 09:39:54 2017 Forteville Gabriel
** Last update Thu Jan 05 10:20:59 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <stdio.h>


int				follow_the_white_rabbit (void)
{
  int			dice;
  int			sum_dice = 0;

  do  {
      dice = rand() % 37 + 1;
      if ((dice > 24 && dice * 3 == 78) || dice % 8 == 0)
	printf("derriere\n");
      if (dice == 4 || dice == 5 || dice == 6 || dice == 28 || (dice >= 17 && dice <= 21))
	printf("gauche\n");
      if (dice == 15 || dice == 10 || dice == 23 )
	printf("devant\n");
      if (dice == 13 || (dice >= 34 && dice != 37))
	printf("droite\n");
      sum_dice += dice;
    } while (dice != 37 && dice != 1 && sum_dice <= 397);
printf("LAPIN !!!\n");
  return sum_dice;
}
