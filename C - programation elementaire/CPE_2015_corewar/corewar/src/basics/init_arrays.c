/*
** init_arrays.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 18:35:35 2016 Hugo Willaume
** Last update Fri Mar 25 11:05:58 2016 Hugo Willaume
*/

void	init_int_array(int *intarray, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      intarray[i] = 0;
      i++;
    }
}

void	init_char_array(char *chararray, char size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      chararray[i] = 0;
      i++;
    }
}
