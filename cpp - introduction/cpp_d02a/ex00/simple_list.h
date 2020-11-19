/*
** simple_list.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02a/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 17:51:17 2017 Forteville Gabriel
** Last update Thu Jan 05 18:56:35 2017 Forteville Gabriel
*/

#ifndef SIMPLE_LIST_H_
# define SIMPLE_LIST_H_

typedef struct s_node
{
  double value;
  struct s_node *next;
} t_node;

typedef t_node * t_list;

typedef enum e_bool
{
  FALSE,
  TRUE
} t_bool;

#endif
