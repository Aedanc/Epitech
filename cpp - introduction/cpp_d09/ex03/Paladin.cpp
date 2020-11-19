/*
** Paladin.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 20:50:21 2017 Forteville Gabriel
// Last update Thu Jan 12 20:59:50 2017 Gabriel Forteville
*/

#include "Paladin.hh"

Paladin::Paladin (std::string const& name, int level):
 Character(name, level),
 Warrior(name, level),
 Priest(name, level) {}

Paladin::Paladin (Paladin const& other):
 Character(other._name, other._level),
 Warrior(other._name, other._level),
 Priest(other._name, other._level) {}

Paladin::~Paladin () {}

int Paladin::CloseAttack()
{
    return Warrior::CloseAttack();
}

int Paladin::RangeAttack()
{
    return Priest::RangeAttack();
}

int Paladin::Intercept()
{
    return Warrior::RangeAttack();
}

void Paladin::heal()
{
    Priest::Heal();
}

void Paladin::RestorePower()
{
    Warrior::RestorePower();
}
