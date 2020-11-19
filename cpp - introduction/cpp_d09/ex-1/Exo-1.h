/*
** ex-1.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex-1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 10:47:58 2017 Forteville Gabriel
** Last update Thu Jan 12 12:05:38 2017 Forteville Gabriel
*/

#ifndef _EX_1_H_
#define _EX_1_H_

typedef struct 	s_cthulhu
{
  int		m_power;
  char		*name;
  void		(*PrintPower)(struct s_cthulhu* this);
  void		(*Attack)(struct s_cthulhu* this);
  void		(*Sleeping)(struct s_cthulhu* this);
  void (*CthulhuInitializer)(struct s_cthulhu* this);

}		t_cthulhu;

typedef struct	s_koala
{
  struct s_cthulhu	m_parent;
  char		m_isALegend;
  void		(*Eat)(struct s_koala* this);
  void		(*KoalaInitializer)(struct s_koala* this, char* _name, char _isALegend);
}		t_koala;

void PrintPower(struct s_cthulhu* this);

void Attack(struct s_cthulhu* this);

void Sleeping(struct s_cthulhu* this);

void Eat(t_koala* this);

t_koala		*NewKoala(char* name, char _isALegend);
t_cthulhu 	*NewCthulhu();


#endif /*_EX_1_H_ */
