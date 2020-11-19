/*
** virtual.h for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 17:43:36 2016 Hugo Willaume
** Last update Sun Mar 27 21:11:36 2016 Hugo Willaume
*/

#ifndef			VIRTUAL_H_
# define		VIRTUAL_H_

# include		"op.h"

# define		TO_KILL		(0)
# define		FOR_NBR_LIVE	(1)
# define		WIN		(0)
# define		LIFE		(1)

char			*get_next_line(const int fd);

# ifndef		READ_SIZE
#  define		READ_SIZE (10)
# endif			/* READ_SIZE */

struct			s_arena
{
  char			arena[MEM_SIZE];
  int			champ_numbers;
  int			current_cycle;
  int			dump[2];
  int			last_living;
};

struct			s_process
{
  char			regs[REG_NUMBER];
  char			carry;
  int			pc;
  int			cycle;
  int			*args;
  struct s_process	*next;
};

struct			s_champions
{
  t_header		*header;
  int			start_address;
  char			*bytecode;
  int			ch_nb;
  unsigned int		live;
  struct s_champions	*next;
  struct s_process	*process;
};

typedef union		s_4chartoint
{
  int			nbrread;
  char			opcode[4];
}			t_4chartoint;

typedef union		s_2ctos
{
  short			nbrread;
  char			opcode[2];
}			t_2ctos;

/*	ABOUT PARSING:
	It's about the command line , and initialising the arena and champions */
int			parsing_user(int ac,
				     char **av,
				     t_champions **champs,
				     t_arena *arena);

int			set_dump_cycles(char *av,
					t_arena *arena);

int			big_read_cor_file(char **arg_suite ,
					  int *i,
					  t_champions **champs);

int			read_cor_file(char *name,
				      t_champions **champs);
/* //////////// */

/*	Init des champions et de l'arène	*/
int			init_arena_champs(t_arena *arena,
					  t_champions *champs);

int			init_arena(t_arena *arena,
				   t_champions *champs);

int			champ_numbers(t_champions *champ);

int			champ_adresses(t_champions *champ,
				       t_arena *arena);

void			place_default_champs(t_champions *champ,
					     t_arena *arena);
/*	////////////		*/

/* instruction (1 fichier par fonction, nom fichier = nom fonction)*/
int			checkchamp(t_champions **champ,
				   t_arena *arena,
				   int check);

char			*readoctecodage(t_arena *coloseum,
					t_process *actualprocess);

int			cycle(t_champions *champ,
			      t_arena *colosseum);

void			my_putaction(t_champions *champion,
				     int check);

/* /////////// */

void			freechamp(t_champions *champafree,
				  t_champions **allchamp);

int			big_endian(int nb);

void			dump_arena(t_arena *arena,
				   t_champions *champ);

void			free_champs(t_champions *);


/*		INSTRUCTIONS FILE :		*/

void			my_live(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_ld(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_st(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_add(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_sub(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_and(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_or(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_xor(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_zjmp(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_ldi(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_sti(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_fork(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_lld(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_lldi(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_lfork(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

void			my_aff(t_champions *champions,
			     t_champions *actualchamp,
			     t_arena *colosseum,
			     t_process *actualprocess);

#endif		/* VIRTUAL_H_ */
