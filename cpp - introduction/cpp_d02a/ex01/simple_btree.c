/*
** simpl_btree.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02a/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 20:20:08 2017 Forteville Gabriel
** Last update Thu Jan 05 22:58:46 2017 Forteville Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_btree.h"

t_bool btree_is_empty(t_tree tree)
{
  return (tree) ? TRUE : FALSE;
}

unsigned int btree_get_size(t_tree tree)
{
  static unsigned int total = 0;

  if (tree == NULL)
    return total;
  total++;
  if (tree->left != NULL)
    btree_get_size(tree->left);
  if (tree->right != NULL)
    btree_get_size(tree->right);
  return total;
}

unsigned int btree_get_depth(t_tree tree)
{
  static unsigned int best_deph = 0;
  static unsigned int actual_deph = 0;

  actual_deph++;
  if (tree == NULL)
    return best_deph;
  if (tree->left != NULL)
    btree_get_depth(tree->left);
  else
    best_deph = (actual_deph > best_deph) ? actual_deph : best_deph;
  if (tree->right != NULL)
    btree_get_depth(tree->right);
  else
    best_deph = (actual_deph > best_deph) ? actual_deph : best_deph;
  actual_deph--;
  return best_deph;
}


t_bool btree_create_node(t_tree *node_ptr, double value)
{
  t_node *new_elem;

  if ((new_elem = calloc(sizeof(t_node), 1)) == NULL)
    return FALSE;
  new_elem->value = value;
  new_elem->left = NULL;
  new_elem->right = NULL;
  *node_ptr = new_elem;
  return TRUE;
}

t_bool btree_delete(t_tree *root_ptr)
{
  if (root_ptr == NULL)
    return FALSE;
  if ((*root_ptr)->right != NULL)
    btree_delete(&((*root_ptr)->right));
  if ((*root_ptr)->left != NULL)
    btree_delete(&((*root_ptr)->left));
  free(*root_ptr);
  *root_ptr = NULL;
  return TRUE;
}


double btree_get_max_value(t_tree tree)
{
  double result = tree->value;
  double tmp;

  if (tree == NULL)
    return 0;
  if (tree->left != NULL)
    result = ((tmp = btree_get_max_value(tree->left)) > result) ? tmp : result;
  if (tree->right != NULL)
    result = ((tmp = btree_get_max_value(tree->right)) > result) ? tmp : result;
  return result;
}

double btree_get_min_value(t_tree tree)
{
  double result = tree->value;
  double tmp;

  if (tree == NULL)
    return 0;
  if (tree->left != NULL)
    result = ((tmp = btree_get_min_value(tree->left)) < result) ? tmp : result;
  if (tree->right != NULL)
    result = ((tmp = btree_get_min_value(tree->right)) < result) ? tmp : result;
  return result;
}
