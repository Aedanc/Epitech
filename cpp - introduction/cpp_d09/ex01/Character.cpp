/*
** Character.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 12:40:39 2017 Forteville Gabriel
** Last update Thu Jan 12 18:41:58 2017 Forteville Gabriel
*/

#include <iostream>
#include "Character.hh"

/* constructeur && destructeur */
Character::Character(std::string const& name, int level):_name(name), _level(level)
{
    _class = "Character";
    _race = "Koala";
    _pv = 100;
    _power = 100;
    _strength = 5;
    _stamina = 5;
    _intelligence = 5;
    _spirit = 5;
    _agility = 5;
    Range = Character::CLOSE;
    std::cout << _name << " Created" << std::endl;
}

Character::Character (Character const& other):_name(other._name), _level(other._level), _pv(other._pv), _power(other._power)
{
    _class = other._class;
    _race = other._race;
    _strength = other._strength;
    _stamina = other._stamina;
    _intelligence = other._intelligence;
    _spirit = other._spirit;
    _agility = other._agility;
    Range = other.Range;
    std::cout << _name << " Created" << std::endl;
}

Character::~Character () {}

/* autre méthode */

int Character::CloseAttack()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " strikes with a wood stick" << std::endl;
    return 10 + _strength;
}

int Character::RangeAttack()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " launches a stone" << std::endl;
    return 5 + _strength;
}

void Character::Heal()
{
    _pv += 50;
    if (_pv > 100)
        _pv = 100;
    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    _power = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int _damage)
{
    _pv -= _damage;
    if (_pv <= 0)
        std::cout << _name <<" out of combat" << std::endl;
    else
        std::cout << _name << " takes " << _damage << " damage" << std::endl;
}

/* getter && setter */

const std::string &Character::getName() const { return _name;}
int Character::getLvl() const { return _level;}
int Character::getPv() const { return _pv;}
int Character::getPower() const { return _power;}

/* surcharge opérateur */

Character Character::operator=(Character const& other)
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
        Range = other.Range;
    }
    return *this;
}
