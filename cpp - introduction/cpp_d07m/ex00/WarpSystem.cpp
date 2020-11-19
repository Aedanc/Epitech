/*
** WarpSystem.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 11:49:48 2017 Forteville Gabriel
** Last update Tue Jan 10 12:16:43 2017 Forteville Gabriel
*/

#include <iostream>
#include "WarpSystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    this->_coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{

}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}
