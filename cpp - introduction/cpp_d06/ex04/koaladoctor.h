/*
** koaladoctor.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex04
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 09 22:12:28 2017 Forteville Gabriel
** Last update Mon Jan 09 22:51:31 2017 Forteville Gabriel
*/

#ifndef __KOALADOCTOR_H_
#define __KOALADOCTOR_H_

#include <string>
#include <iostream>
#include "sickkoala.h"

class KoalaDoctor
{
  public:
    KoalaDoctor(std::string);
    ~KoalaDoctor();

  void diagnose(SickKoala *patient);
  void timeCheck();
  private:
    std::string name;
};

#endif
