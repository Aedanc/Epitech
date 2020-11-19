/*
** droid.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d08/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 11 10:47:32 2017 Forteville Gabriel
** Last update Thu Jan 12 00:32:45 2017 Forteville Gabriel
*/

#include <iostream>
#include "droid.hh"

/* construct && destruct */
Droid::Droid(std::string id):_attack(25), _toughness(15)
{
    std::string *status = new std::string("Standing by");
    this->_status = status;
    this->_energy = 50;
    this->_id = id;
    std::cout << "Droid '" << id << "' Activated" << std::endl;
};

Droid::Droid(Droid const& other):_attack(other.getAttack()), _toughness(other.getToughness())
{
    std::string *status = new std::string(*other.getStatus());
    this->_status = status;
    this->_energy = other.getEnergy();
    this->_id = other.getId();
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

/* setter */
void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        energy = 100;
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    if (this->_status != status)
        delete (this->_status);
    this->_status = status;
}

/* getter */
std::string Droid::getId() const
{
    return (this->_id);
}

size_t Droid::getEnergy() const
{
    return this->_energy;
}

size_t Droid::getAttack() const
{
    return this->_attack;
}

size_t Droid::getToughness() const
{
    return this->_toughness;
}

const std::string* Droid::getStatus() const
{
    return this->_status;
}

/* overload operator */


void Droid::operator=(Droid const& other)
{
    if (*this != other)
    {
        std::string *status = new std::string(*other.getStatus());
        if (this->_status)
            delete(this->_status);
        this->_status = status;
        this->_energy = other.getEnergy();
        this->_id = other.getId();
    }
}

bool Droid::operator==(Droid const& other) const
{
    return (this->_id == other.getId() && this->_energy == other.getEnergy() && *this->_status == *other.getStatus());
}

bool Droid::operator!=(Droid const& other) const
{
    return !operator==(other);
}

size_t& Droid::operator<<(size_t &source)
{
    int tmp = source;

    tmp -= 100 - this->_energy;
    if (tmp < 0)
        tmp = 0;
    this->setEnergy(this->getEnergy() + (source - tmp));
    source = tmp;
    return (source);
}
std::ostream& operator<<(std::ostream& os, Droid const& droid)
{
    os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return os;
}
