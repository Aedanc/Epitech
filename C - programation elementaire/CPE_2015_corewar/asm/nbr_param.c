/*
** nbr_param.c for nbr_param in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/vermeu/
**
** Made by vermeu_v
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Wed Mar 23 17:04:35 2016 vermeu_v
** Last update Wed Mar 23 17:12:34 2016 vermeu_v
*/

int	nbr_param(char **line_pars)
{
  int	cpt;

  cpt = 0;
  while (line_pars[cpt] != NULL)
    cpt++;
  return (cpt);
}
