/*
** Parts.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07a/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 20:44:03 2017 Forteville Gabriel
** Last update Wed Jan 11 00:43:57 2017 Forteville Gabriel
*/

#ifndef __PARTS_H_
#define __PARTS_H_ value

#include <iostream>

class Arms{

  public:
  Arms(std::string const& serial, bool functionnal);
  ~Arms();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

  private:
   std::string _serial;
   bool _functionnal;
}; /* Arms */

class Legs{

  public:
  Legs(std::string const& serial, bool functionnal);
  ~Legs();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

  private:
   std::string _serial;
   bool _functionnal;
}; /* Legs */


class Head{

  public:
  Head(std::string const& serial, bool functionnal);
  ~Head();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

  private:
   std::string _serial;
   bool _functionnal;
}; /* Head */

class KoalaBot {

public:
  KoalaBot(std::string serial);
  ~KoalaBot();
  void setParts(Arms arms);
  void setParts(Legs legs);
  void setParts(Head head);


private:
  Arms _Arms;
  Legs _Legs;
  Head _head;
  std::string _serial;

};
#endif /* __PARTS_H_ */
