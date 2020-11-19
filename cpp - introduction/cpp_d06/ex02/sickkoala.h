/*
** SickKoala.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 09 14:02:37 2017 Forteville Gabriel
** Last update Mon Jan 09 16:12:33 2017 Forteville Gabriel
*/

#ifndef __SICKKOALA_H_
#define __SICKKOALA_H_

#include <string>
#include <iostream>

class SickKoala
{
public:
  SickKoala(std::string name);
  ~SickKoala();

  void poke();
  bool takeDrug(std::string);
  void overDrive(std::string);
private:
  std::string name;


};

#endif /* __SICKKOALA_H_ */
