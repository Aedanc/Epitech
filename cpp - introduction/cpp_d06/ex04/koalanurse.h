/*
** koalanurse.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 09 16:47:13 2017 Forteville Gabriel
** Last update Mon Jan 09 21:23:46 2017 Forteville Gabriel
*/

#ifndef __KOALANURSE_H_
#define __KOALANURSE_H_

#include <string>
#include <iostream>
#include "sickkoala.h"

class	KoalaNurse
{
public:
  KoalaNurse(int id);
  ~KoalaNurse();

  void giveDrug(std::string drug, SickKoala *patient);
  std::string readReport(std::string drug);
  void timeCheck();
private:
  int id;
  bool workNow;
};

#endif
