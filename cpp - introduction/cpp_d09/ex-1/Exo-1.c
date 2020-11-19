/*
** ex-1.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex-1
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 10:47:51 2017 Forteville Gabriel
** Last update Thu Jan 12 12:11:26 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ex-1.h"

void PrintPower(struct s_cthulhu* this)
{
 printf("Power => %i\n", this->m_power);
}

void Attack(struct s_cthulhu* this)
{
  if (this->m_power >= 42)
    {
      this->m_power -= 42;
      printf("%s attacks and destroys the city\n", this->name);
    }
  else
    {
      printf("%s can't attack, he doesn't have enough power\n", this->name);
    }
}

void Sleeping(struct s_cthulhu* this)
{
  this->m_power +=42000;
  printf("%s spleeps\n", this->name);
}

void Eat(t_koala* this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.name);
}

static void CthulhuInitializer(t_cthulhu* this)
{
  this->name = strdup("Cthulhu");
  this->m_power = 42;
  this->PrintPower = PrintPower;
  this->Attack = Attack;
  this->Sleeping = Sleeping;
  printf("----\nBuilding Cthulhu\n");
}

t_cthulhu *NewCthulhu()
{
  t_cthulhu *result;

  result = malloc(sizeof(t_cthulhu));
  result->CthulhuInitializer = CthulhuInitializer;
  result->CthulhuInitializer(result);
  return result;
}

static void KoalaInitializer(t_koala* this, char* name, char _isALegend)
{
  CthulhuInitializer(&(this->m_parent));
  this->m_isALegend = 1;
  if (_isALegend == 0)
    this->m_parent.m_power = 0;
  else
    this->m_isALegend = 1;
  free(this->m_parent.name);
  this->m_parent.name = strdup(name);
  this->Eat = Eat;
  printf("Building %s\n", name);
}

t_koala		*NewKoala(char* name, char _isALegend)
{
  t_koala  	*result;

  result = malloc(sizeof(t_koala));
  result->KoalaInitializer = KoalaInitializer;
  result->KoalaInitializer(result, name, _isALegend);
  return result;
}
