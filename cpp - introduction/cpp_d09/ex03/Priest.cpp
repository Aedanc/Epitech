/*
** Priest.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 17:25:04 2017 Forteville Gabriel
// Last update Thu Jan 12 21:00:19 2017 Gabriel Forteville
*/

#include "Priest.hh"

Priest::Priest(std::string name, int level): Character(name, level), Mage(name, level)
{
    _strength = 4;
    _stamina = 4;
    _intelligence = 42;
    _spirit = 21;
    _agility = 2;
    std::cout << _name << "enters in the order" << std::endl;
}

Priest::Priest(Priest const& other): Character(other), Mage(other)
{

}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    std::cout << _name << " uses a spirit explosion" << std::endl;
    _power -= 10;
    return 5 + _strength;
}

void Priest::Heal()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return ;
    }
    _pv += 70;
    if (_pv > 100)
        _pv = 100;
        std::cout << _name << "casts a little heal spel" << std::endl;
}
