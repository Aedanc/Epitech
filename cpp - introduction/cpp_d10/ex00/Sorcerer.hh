/*
** Sorcerer.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 13 10:14:17 2017 Forteville Gabriel
// Last update Fri Jan 13 13:58:20 2017 Gabriel Forteville
*/

#ifndef __SORCERER_HH_
#define __SORCERER_HH_

#include <iostream>
#include <string>
#include "Victim.hh"

class Sorcerer
{
    private:
        std::string _name;
        std::string _title;

    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const& other);
        virtual ~Sorcerer();

        std::string getName() const;
        std::string getTitle() const;
        void polymorph(Victim const& plop) const;
};

std::ostream& operator<<(std::ostream& os, Sorcerer const& sorcerer);

#endif
