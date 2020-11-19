/*
** big_endian.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Fri Mar 25 13:13:19 2016 Hugo Willaume
** Last update Sun Mar 27 05:30:25 2016 Hugo Willaume
*/

#include	"virtual.h"

int		big_endian(int nb)
{
  t_4chartoint	uni;
  char		tmp;

  uni.nbrread = nb;
  tmp = uni.opcode[0];
  uni.opcode[0] = uni.opcode[3];
  uni.opcode[3] = tmp;
  tmp = uni.opcode[1];
  uni.opcode[1] = uni.opcode[2];
  uni.opcode[2] = tmp;
  return (uni.nbrread);
}
