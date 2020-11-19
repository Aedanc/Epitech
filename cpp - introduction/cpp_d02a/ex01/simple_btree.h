/*
** simple_btree.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02a/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 20:18:24 2017 Forteville Gabriel
** Last update Thu Jan 05 20:29:00 2017 Forteville Gabriel
*/

#ifndef SIMPLE_BTREE_H_
#define SIMPLE_BTREE_H_

typedef struct s_node
{
  double value;
  struct s_node *left;
  struct s_node *right;
} t_node;

typedef t_node *t_tree;

typedef enum e_bool
{
  FALSE,
  TRUE
} t_bool;

#endif
