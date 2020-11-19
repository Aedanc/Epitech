/*
** my.h for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Dec  7 17:34:09 2015 Forteville Gabriel
** Last update Fri May 13 14:58:36 2016 Forteville Gabriel
*/

#ifndef MY_H_
# define MY_H_

# define TRUE (1)
# define FALSE (0)

typedef		char bool;

/*
**	hub function
*/

char		**doshell(char **userinput,
			  char **env,
			  char **need_free);

/*
**	my_builtins
*/

int		my_exit(char **av,
			char **env,
			char **need_free);

int		my_env(char **env);

char		**my_setenv(char **value,
			    char **env);

char		**my_cd(char **input,
			char **env);

char		**my_unsetenv(char **input,
			      char **env);

/*
**	only for minishell
*/

char		*my_path(char *str1,
			 char *str2);

bool		is_builting(char **input,
			    char **env);

char		*my_newvarenv(char *str1,
			      char *str2,
			      bool str1_is_malloc,
			      bool str2_is_malloc2);

char		*clean_input(char *tmp,
			     bool ismalloc);

char		**clean_all_input(char **tmp,
				  bool ismalloc);

void		free_tab(char **userinput);

int		try_to_exe(char **input,
			   int i,
			   char **env,
			   unsigned char result);

char		**condition(char **env,
			  char tmp[4096],
			  int  stop);

void		check_result(int result);

char		*no_tab(char *str);

void		first_command(int **tab_pipe_fd,
			      char *command,
			      char **env);

void		mid_command(int **tab_pipe_fd,
			    int index,
			    char *command,
			    char **env);

void		last_command(int **tab_pipe_fd,
			     int index,
			     char *command,
			     char **env);

int		**close_tab_pipe(int **tab_pipe_fd,
				 int one_ellem,
				 bool need_close[2]);

char		**remalloc_env(char **env,
			       bool check);

char		**multi_pipe(char *input,
			     char **env);

int		findpath(char **env);

/*
**	basic
*/

void		my_putchar(char c);

int		my_strlen(char *str);

int		my_tablen(char **tab);

int		my_putstr(char *str);

int		my_strcompare(char *str1,
			      char *str2,
			      int i);

int		**my_malloc_tab_tab_int(int len_tab_tab,
					int len_tab);

void		my_free_tab_tab_int(int **tab_tab_int);

char		*my_strcpy(char *str,
			   int start,
			   int end);

int		my_get_nbr(char *str,
			   int i);

char		**my_str_to_word_tab(char *str,
				     char c);

int		my_show_word_tab(char **str);

char		*my_epurstr(char *str,
			    char separator,
			    bool ismalloc);

int		my_puterror(char *errorstr);

char		*tow_to_one(char *str1,
			    char *str2,
			    bool malloc1,
			    bool malloc2);

#endif
