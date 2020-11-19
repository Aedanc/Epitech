/*
** Warrior.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 14:21:22 2017 Forteville Gabriel
** Last update Thu Jan 12 18:41:46 2017 Forteville Gabriel
*/


#include <iostream>
#include "Warrior.hh"
#include "Character.hh"

/* constructeur && destructeur */
Warrior::Warrior(std::string const& name, int level): Character(name, level)
{
    _weapon = "hammer";
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _agility = 7;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior (Warrior const& other): Character(other)
{
    _weapon = other._weapon;
}

Warrior::~Warrior ()
{

}

/* autre méthode */

int Warrior::CloseAttack()
{
    if (_power < 30)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 30;
    std::cout << _name << " strikes with his " << _weapon << std::endl;
    return 20 + _strength;
}

int Warrior::RangeAttack()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " intercepts" << std::endl;
    Range = CLOSE;
    return 5 + _strength;
}


/* surcharge opérateur */

Warrior Warrior::operator=(Warrior const& other)
{
    if (this != &other)
    {
        _name = other._name;
        _level = other._level;
        _pv = other._pv;
        _power = other._power;
        _strength = other._strength;
        _stamina = other._stamina;
        _intelligence = other._intelligence;
        _spirit = other._spirit;
        _agility = other._agility;
        _weapon = other._weapon;
         Range = other.Range;
    }
    return *this;
}
