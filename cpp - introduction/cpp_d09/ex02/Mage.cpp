/*
** Mage.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 15:58:42 2017 Forteville Gabriel
** Last update Fri Jan 13 09:57:37 2017 Forteville Gabriel
*/

#include "Mage.hh"

Mage::Mage (std::string const& name, int level): Character(name, level)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _agility = 7;
    _spirit = 11;
    _agility = 7;
    std::cout << name << " teleported" << std::endl;
}

Mage::Mage(Mage const& mage)
{

}

Mage::~Mage()
{

}

int Mage::CloseAttack()
{
    if (_power < 10)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " blinks" << std::endl;
    Range = RANGE;
    return 0;
}

int Mage::RangeAttack()
{
    if (_power < 25)
    {
        std::cout << _name << "out of power" << std::endl;
        return 0;
    }
    _power -= 25;
    std::cout << _name << " launches a fire ball" << std::endl;
    return 20 + _spirit;
}

void Mage::RestorePower()
{
    _power += 50 + _intelligence;
    if (_power > 100)
        _power = 100;
    std::cout << _name << " takes a mana potion" << std::endl;
}
