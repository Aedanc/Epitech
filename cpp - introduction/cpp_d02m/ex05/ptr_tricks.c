/*
**ptr_tricks.cforpiscine_cppin/home/fortevg/rendu/piscine_cpp/cpp_d02m/ex05
**
**MadebyFortevilleGabriel
**Login<fortevg@epitech.net>
**
**StartedonThuJan0515:43:292017FortevilleGabriel
** Last update Thu Jan 05 17:42:03 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <stdio.h>
#include "prt_triks.h"

t_whatever *get_struct_ptr(int *member_ptr)
{
  t_whatever test_struct;
  t_whatever *result;

  result = (t_whatever *)(member_ptr +  (((long)&(test_struct) - (long)&(test_struct.member)) / 4));
  return result;
}

int get_array_nb_elem(int *ptr1, int *ptr2)
{
  return abs((int)(ptr2 - ptr1));
}

int main(void)
{
  t_whatever test;
  t_whatever *ptr;
  ptr = get_struct_ptr(&test.member);
  if(ptr == &test)
    printf("It works!\n");
  return 0;
}
