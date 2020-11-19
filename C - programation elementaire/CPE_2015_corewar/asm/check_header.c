/*
** check_header.c for check_header in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/baldas/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Fri Mar 25 04:00:44 2016 vermeu_v
** Last update Sun Mar 27 23:13:31 2016 vermeu_v
*/

#include	"op.h"
#include	"my.h"
#include	"convert.h"

int		check_header(char **line_pars, t_header *header)
{
  if ((my_strcmp(line_pars[0], NAME_CMD_STRING)) == 0)
    {
      in_header(line_pars[1], header->prog_name);
      return (1);
    }
  else if ((my_strcmp(line_pars[0], COMMENT_CMD_STRING)) == 0)
    {
      in_header(line_pars[1], header->comment);
      return (1);
    }
  return (0);
}
