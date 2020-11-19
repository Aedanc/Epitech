/*
** file_errors_display.c for file_errors_display in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Mar 24 16:17:38 2016 Hugo Baldassin
** Last update Thu Mar 24 16:24:39 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"

void		file_errors_display(int flag, char *name)
{
  if (flag == -6)
    {
      fake_printf("File ", 0, name, " not accessible.\n");
      exit(flag);
    }
  else if (flag == -8)
    {
      fake_printf("Error: file ", 0, name, " is empty.\n");
      exit(flag);
    }
  else
    fake_printf("Error closing ", 0, name, "\n");
}
