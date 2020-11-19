/*
** Priest.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 17:20:53 2017 Forteville Gabriel
** Last update Thu Jan 12 20:43:29 2017 Forteville Gabriel
*/


#ifndef __Priest_HH_
#define __Priest_HH_

#include <iostream>
#include "Mage.hh"

class Priest : public Mage
{
    private:

    public:
        Priest(std::string name, int level);
        Priest(Priest const& other);
        ~Priest();

        int CloseAttack();
        void Heal();

};

#endif
