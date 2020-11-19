/*
** Warrior.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 14:21:26 2017 Forteville Gabriel
** Last update Thu Jan 12 15:44:17 2017 Forteville Gabriel
*/


#ifndef __Warrior_HH_
#define __Warrior_HH_

#include <iostream>
#include "Character.hh"

class Warrior : public Character
{
    protected:
        std::string _weapon;

    public:
        Warrior(std::string const& name, int level);
        Warrior(Warrior const& other);
        ~Warrior ();

        int CloseAttack();
        int RangeAttack();
        Warrior operator=(Warrior const& other);

};

#endif
