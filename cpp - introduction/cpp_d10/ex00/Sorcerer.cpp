/*
** Sorcerer.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 13 10:14:15 2017 Forteville Gabriel
// Last update Fri Jan 13 14:05:16 2017 Gabriel Forteville
*/

#include <iostream>
#include <string>
#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title):
_name(name),
_title(title)
{
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const& other):
_name(other._name),
_title(other._title)
{

}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const& plop) const
{
  plop.getPolymorphed();
}

std::string Sorcerer::getName() const { return _name; }

std::string Sorcerer::getTitle() const { return _title; }

std::ostream& operator<<(std::ostream& os, Sorcerer const& sorcerer)
{
  os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
    return os;
}
