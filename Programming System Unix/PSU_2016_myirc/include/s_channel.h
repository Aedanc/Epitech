/*
** s_channel.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Sun Jun 11 18:12:22 2017 Pauline Maes
** Last update Sun Jun 11 18:13:24 2017 Pauline Maes
*/

#ifndef			S_CHANNEL_H_
# define		S_CHANNEL_H_

typedef struct		s_channel
{
  char			*name;
  char			**cmd;
  struct s_channel	*next;
}			s_channel;

#endif			/* !S_CHANNEL_H_ */
