/*
** menger.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@ependech.net>
**
** Started on  Wed Jan 04 15:00:03 2017 Forteville Gabriel
** Last update Wed Jan 04 22:34:21 2017 Forteville Gabriel
*/

#include 			<stdlib.h>
#include			<stdio.h>

void					menger(int size, int pa, int po, int end)
{
  size = size / 3;
  if (end == 1)
    return ;
    printf("%03d %03d %03d\n", size, pa - size * 2, po - size * 2);
    menger(size, pa - size * 2, po - size * 2, end - 1);
    printf("%03d %03d %03d\n", size, pa - size * 2, po + size);
    menger(size, pa - size * 2, po + size, end - 1);
    printf("%03d %03d %03d\n", size, pa - size * 2, po + size * 4);
    menger(size, pa - size * 2, po + size * 4, end - 1);
    printf("%03d %03d %03d\n", size, pa + size, po - size * 2);
    menger(size, pa + size, po - size * 2, end - 1);
    printf("%03d %03d %03d\n", size, pa + size, po + size * 4);
    menger(size, pa + size, po + size * 4, end - 1);
    printf("%03d %03d %03d\n", size, pa + size * 4, po - size * 2);
    menger(size, pa + size * 4, po - size * 2, end - 1);
    printf("%03d %03d %03d\n", size, pa + size * 4, po + size * 1);
    menger(size, pa + size * 4, po + size * 1, end - 1);
    printf("%03d %03d %03d\n", size, pa + size * 4, po + size * 4);
    menger(size, pa + size * 4, po + size * 4, end - 1);
}
