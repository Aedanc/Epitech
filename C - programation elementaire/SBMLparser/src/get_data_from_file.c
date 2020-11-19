/*
** get_data_from_file.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jun 13 16:57:28 2016 Forteville Gabriel
** Last update Wed Jun 15 15:28:49 2016 Forteville Gabriel
*/

#define 	_GNU_SOURCE
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"struct.h"
#include	"basic.h"

static char		*use_getline(FILE *stream)
{
  size_t		len;
  char			*line;

  len = 0;
  line = NULL;
  if (getline(&line, &len, stream) == -1)
    {
      free(line);
      return (NULL);
    }
  line[len - 1] = 0;
  return (line);
}

static void		check_path(const char *path_file,
				   FILE **stream,
				   t_data **info_file)
{
  int			index;
  int			omg;

  index = 0;
  while (path_file[index] != 0)
    index++;
  if ((omg = my_strncmp(path_file, ".sbml", index - 5, -1)) != 0)
    {
      fprintf(stderr, "error: file has not the .sbml extension\n");
      exit(84);
    }
  if ((*stream = fopen(path_file, "r")) == NULL ||
      (*info_file = malloc(sizeof(t_data))) == NULL)
    {
      perror("error open");
      exit(84);
    }
}

static	void		check_line(const char *line, const int nbr_line)
{
  int			index_end;
  int			index_start;

  if (line != NULL)
    {
      index_end = 0;
      index_start = 0;
      while (line[index_end] != 0 && line[index_end] != '\n')
	index_end++;
      while (line[index_start] == ' ' || line[index_start] == '\t')
	index_start++;
      if (line[index_start] != '<' || line[index_end - 1] != '>')
	{
	  fprintf(stderr, "error: format XML wrong at line %i\n", nbr_line);
	  exit (84);
	}
    }
}

static t_data			*fill_linked_list(t_data *info_file,
						  FILE *stream,
						  char *tmp_line)
{
  int			line;
  t_data		*tmp;
  t_data		*tmp_prev;

  line = 0;
  tmp = info_file;
  while (tmp_line != NULL && my_strlen(tmp_line) != 0)
    {
      tmp->next = NULL;
      line++;
      check_line(tmp_line, line);
      tmp->info_line = my_str_to_wordtab(tmp_line, "<?> \t,=");
      if ((tmp->next = malloc(sizeof(t_data))) == NULL)
	return (NULL);
      tmp_prev = tmp;
      tmp = tmp->next;
      free(tmp_line);
      tmp_line = use_getline(stream);
    }
  free(tmp_prev->next);
  tmp_prev->next = NULL;
  return (info_file);
}

t_data			*get_data_from_file(const char *path_file)
{
  FILE			*stream;
  t_data		*info_file;
  char			*tmp_line;

  check_path(path_file, &stream, &info_file);
  tmp_line = use_getline(stream);
  info_file = fill_linked_list(info_file, stream, tmp_line);
  if (stream != NULL)
    fclose(stream);
  return (info_file);
}
