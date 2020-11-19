/*
** main.c for  in /home/fortevg/rendu/piscine_cpp/cpp_SKL/ex04
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun Jan  8 04:23:43 2017 Gabriel Forteville
** Last update Sun Jan  8 05:32:36 2017 Hugo Baldassin
*/

#include <stdlib.h>
#include <stdio.h>
#include "raise.h"
#include "object.h"
#include "new.h"
#include "bool.h"
#include "char.h"
#include "int.h"
#include "float.h"

int	main()
{
  Class *float_test;
  Class *float_test2;

  float_test = new(Float, 34.2);
  float_test2 = new(Float, 4.2);

  printf("FLOAT\n%s + %s = %s \n"
	 "%s - %s = %s\n"
	 "%s * %s = %s\n"
	 "%s / %s = %s\n"
	 "%s == %s = %d\n"
	 "%s == %s = %d\n"
	 "%s > %s = %d\n"
	 "%s > %s = %d\n"
	 "%s < %s = %d\n"
	 "%s < %s = %d\n ",
	 str(float_test), str(float_test2), str(float_test->__add__(float_test, float_test2)),
	 str(float_test), str(float_test2), str(float_test->__sub__(float_test, float_test2)),
	 str(float_test), str(float_test2), str(float_test->__mul__(float_test, float_test2)),
	 str(float_test), str(float_test2), str(float_test->__div__(float_test, float_test2)),
	 str(float_test), str(float_test), float_test->__eq__(float_test, float_test),
	 str(float_test), str(float_test2), float_test->__eq__(float_test, float_test2),
	 str(float_test), str(float_test2), float_test->__gt__(float_test, float_test2),
	 str(float_test2), str(float_test), float_test->__gt__(float_test2, float_test),
	 str(float_test), str(float_test2), float_test->__lt__(float_test, float_test2),
	 str(float_test2), str(float_test), float_test->__lt__(float_test2, float_test));

  delete(float_test);
  delete(float_test2);

  Class *int_test;
  Class *int_test2;

  int_test = new(Int, 34);
  int_test2 = new(Int, 4);

  printf("\nINT\n"
	 "%s + %s = %s \n"
	 "%s - %s = %s\n"
	 "%s * %s = %s\n"
	 "%s / %s = %s\n"
	 "%s == %s = %d\n"
	 "%s == %s = %d\n"
	 "%s > %s = %d\n"
	 "%s > %s = %d\n"
	 "%s < %s = %d\n"
	 "%s < %s = %d\n ",
	 str(int_test), str(int_test2), str(int_test->__add__(int_test, int_test2)),
	 str(int_test), str(int_test2), str(int_test->__sub__(int_test, int_test2)),
	 str(int_test), str(int_test2), str(int_test->__mul__(int_test, int_test2)),
	 str(int_test), str(int_test2), str(int_test->__div__(int_test, int_test2)),
	 str(int_test), str(int_test), int_test->__eq__(int_test, int_test),
	 str(int_test), str(int_test2), int_test->__eq__(int_test, int_test2),
	 str(int_test), str(int_test2), int_test->__gt__(int_test, int_test2),
	 str(int_test2), str(int_test), int_test->__gt__(int_test2, int_test),
	 str(int_test), str(int_test2), int_test->__lt__(int_test, int_test2),
	 str(int_test2), str(int_test), int_test->__lt__(int_test2, int_test));

  delete(int_test);
  delete(int_test2);

  Class *char_test;
  Class *char_test2;

  char_test = new(Char, 12);
  char_test2 = new(Char, 5);

  printf("\nCHAR\n"
	 "%s + %s = %s\n"
	 "%s - %s = %s\n"
	 "%s * %s = %s\n"
	 "%s / %s = %s\n"
	 "%s == %s = %d\n"
	 "%s == %s = %d\n"
	 "%s > %s = %d\n"
	 "%s > %s = %d\n"
	 "%s < %s = %d\n"
	 "%s < %s = %d\n",
	 str(char_test), str(char_test2), str(char_test->__add__(char_test, char_test2)),
	 str(char_test), str(char_test2), str(char_test->__sub__(char_test, char_test2)),
	 str(char_test), str(char_test2), str(char_test->__mul__(char_test, char_test2)),
	 str(char_test), str(char_test2), str(char_test->__div__(char_test, char_test2)),
	 str(char_test), str(char_test), char_test->__eq__(char_test, char_test),
	 str(char_test), str(char_test2), char_test->__eq__(char_test, char_test2),
	 str(char_test), str(char_test2), char_test->__gt__(char_test, char_test2),
	 str(char_test2), str(char_test), char_test->__gt__(char_test2, char_test),
	 str(char_test), str(char_test2), char_test->__lt__(char_test, char_test2),
	 str(char_test2), str(char_test), char_test->__lt__(char_test2, char_test));

  delete(char_test);
  delete(char_test2);

  return 0;
};
