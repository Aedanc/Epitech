/*
** execute.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 24 20:41:57 2016 Forteville Gabriel
** Last update Sat Jun 25 18:02:08 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"basic.h"

static char		*final_command(char *name, char *arg)
{
  char			*result;
  char			**tab;

  result = strdup(name);
  if ((result = realloc(result, sizeof(char) * (strlen(name) + strlen(arg)
				       + 2))
       ) == NULL)
    error("fail malloc 1");
  result = strcat(result, arg);
  if (fork() == 0)
    {
      tab = my_str_to_wordtab(result, " ");
      execvp(name, tab);
      freetab(tab);
      exit (1);
    }
  else
    wait(NULL);
  return (result);
}

static void		exec(char *line, char *command)
{
  char			*args;
  char			*tmp;
  int			index_line;
  int			index_args;

  index_line = 5;
  index_args = 0;
  if (line != NULL && strlen(line) == 0)
    {
      dprintf(1, "\n");
      return ;
    }
  if ((args = malloc(sizeof(char) * (strlen(line) - 4))) == NULL)
    error("fail malloc 2");
  while (line[index_line] != 0)
    {
      args[index_args] = line[index_line];
      index_line++;
      index_args++;
    }
  args[index_args] = 0;
  tmp = final_command(command, args);
  free(tmp);
  free(args);
}

static void		print_test(char *name_file, char *command)
{
  FILE			*stream;
  char			*line;
  size_t		len;

  len = 0;
  line = NULL;
  stream = fopen(name_file, "r");
  getline(&line, &len, stream);
  while (line != NULL && strlen(line) != 0 && strncmp(line, "ARGS:", 5) != 0)
    {
      if (strncmp(line, "INPUT:", 6) == 0)
	open_file(line + 6);
      len = 0;
      free(line);
      line = NULL;
      getline(&line, &len, stream);
    }
  if (line != NULL)
    exec(line, command);
  free(line);
  fclose(stream);
  return ;
}

static void		print_real_path(char *real_path, char *name_dir,
					char *name_file, char *command)
{
  char		**cut_path;
  char		**cut_dir;
  int		index_cut;
  int		index_dir;

  index_cut = 0;
  cut_path = my_str_to_wordtab(real_path, "/");
  cut_dir = my_str_to_wordtab(name_dir, "/");
  index_dir = tablen(cut_dir) - 1;
  while (cut_path && cut_path[index_cut] && strcmp(cut_path[index_cut],
						   cut_dir[index_dir]) != 0)
    index_cut++;
  while (cut_path != NULL && cut_path[++index_cut] != NULL)
    dprintf(1, "[%s] ", cut_path[index_cut]);
  index_cut = -1;
  while (name_file[++index_cut] != '.')
    dprintf(1, "%c", name_file[index_cut]);
  dprintf(1, ": ");
  print_test(name_file, command);
  freetab(cut_path);
  freetab(cut_dir);
}

void		execute(char *name_dir, char *name_file, char *command)
{
  char		*real_path;

  real_path = NULL;
  real_path = getcwd(NULL, 0);
  print_real_path(real_path, name_dir, name_file, command);
  free(real_path);
}
