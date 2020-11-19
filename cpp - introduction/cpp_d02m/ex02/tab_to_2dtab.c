/*
** tab_to_2dtab.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02m/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 12:15:34 2017 Forteville Gabriel
** Last update Thu Jan 05 13:20:31 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void		tab_to_2dtab(int *tab,int length,int width,int ***res)
{
  int trav = 0;

  if (((*res) = calloc((length), sizeof(int *))) == NULL) return ;
  for (int i = 0; i < length; i++) {
    if  (((*res)[i] = calloc((width), sizeof(int))) == NULL) return ;
		for (int j = 0; j < width; j++) {
	  (*res)[i][j] = tab[trav];
		trav++;
		}
	}
}
