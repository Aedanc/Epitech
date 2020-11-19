/*
** Parts.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07a/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 20:44:06 2017 Forteville Gabriel
** Last update Wed Jan 11 00:44:20 2017 Forteville Gabriel
*/

#include <iostream>
#include "Parts.h"

Arms::Arms(std::string const& serial = "A-01", bool functionnal = true)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Arms::~Arms()
{

}

bool Arms::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::string functionnal = (this->_functionnal) ? "OK" : "KO";
    std::cout << "[Parts] Arms " << this->_serial << " status : " << functionnal << std::endl;
}






Legs::Legs(std::string const& serial = "L-01", bool functionnal = true)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Legs::~Legs()
{

}

bool Legs::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::string functionnal = (this->_functionnal) ? "OK" : "KO";
    std::cout << "[Parts] Legs " << this->_serial << " status : " << functionnal << std::endl;
}


Head::Head(std::string const& serial = "H-01", bool functionnal = true)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Head::~Head()
{

}

bool Head::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::string functionnal = (this->_functionnal) ? "OK" : "KO";
    std::cout << "[Parts] Head " << this->_serial << " status : " << functionnal << std::endl;
}


KoalaBot::KoalaBot(std::string serial = "Bob-01")
{
    this->_serial = serial;
}

KoalaBot::KoalaBot()
