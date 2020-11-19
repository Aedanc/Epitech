/*
** Skat.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07a/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 17:34:24 2017 Forteville Gabriel
** Last update Tue Jan 10 19:28:52 2017 Forteville Gabriel
*/

#ifndef __SKAT_H_
#define __SKAT_H_

#include <iostream>

class Skat
{
 public:
  Skat(std::string const& name, int stimPaks);
  ~Skat();

  unsigned int& stimPaks();
  const std::string& name();

  void shareStimPaks(int number, unsigned int& stock);
  void addStimPaks(unsigned int number);
  void useStimPaks();

  void status();

 private:
  unsigned int _stimPaks;
  std::string _name;
};

#endif /* __SKAT_H_ */
