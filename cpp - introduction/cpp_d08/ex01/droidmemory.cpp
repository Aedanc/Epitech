/*
** droidmemory.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d08/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 11 15:56:45 2017 Forteville Gabriel
** Last update Thu Jan 12 00:03:32 2017 Forteville Gabriel
*/

#include <iostream>
#include <cstdlib>
#include "droidmemory.hh"

/* constructeur / destructeur */
DroidMemory::DroidMemory ()
{
    this->_fingerPrint = rand();
    this->_exp = 0;
}

DroidMemory::~DroidMemory ()
{

}

 /* setter */
void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

void DroidMemory::setFingerPrint(size_t fingerPrint)
{
    this->_fingerPrint = fingerPrint;
}

/* getter */
size_t DroidMemory::getFingerPrint() const
{
    return this->_fingerPrint;
}

size_t DroidMemory::getExp() const
{
    return this->_exp;
}

/* overload operator */
DroidMemory DroidMemory::operator<<(DroidMemory const& source)
{
    this->_exp += source.getExp();
    this->_fingerPrint = this->_fingerPrint ^ source.getFingerPrint();
    return *this;
}

DroidMemory DroidMemory::operator>>(DroidMemory &dest)
{
    dest.setExp(this->_exp + dest.getExp());
    dest.setFingerPrint(this->_fingerPrint ^ dest.getFingerPrint());
    return (dest);
}

DroidMemory DroidMemory::operator+=(DroidMemory const& source)
{
    return (operator<<(source));
}

DroidMemory DroidMemory::operator+=(size_t const& source)
{
    this->_exp += source;
    this->_fingerPrint = this->_fingerPrint ^ source;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory const& source) const
{
    DroidMemory result;

    result._exp = this->_exp + source.getExp();
    result._fingerPrint = this->_fingerPrint ^ source.getFingerPrint();
    return result;
}

DroidMemory DroidMemory::operator+(size_t const& source) const
{
    DroidMemory result;

    result._exp = this->_exp + source;
    result._fingerPrint = this->_fingerPrint ^ source;
    return result;
}

std::ostream& operator<<(std::ostream& os, DroidMemory const& source)
{
    os << "DroidMemory ’" << source.getFingerPrint() << "’, " << source.getExp();
    return os;
}
