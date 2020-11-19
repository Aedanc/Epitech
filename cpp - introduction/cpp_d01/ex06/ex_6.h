/*
** ex_06.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex06
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 04 22:46:36 2017 Forteville Gabriel
** Last update Thu Jan 05 10:30:37 2017 Forteville Gabriel
*/

#ifndef EX_6_H_
# define EX_6_H_

typedef union u_bar1
{
  int foo;
  int bar;
} t_bar1;

typedef struct s_foo2
{
  int foo;
  t_bar1 bar;
} t_foo2;

typedef union u_foo
{
  t_foo2 foo;
  int bar;
} t_foo;

#endif /* EX_6_H_ */
