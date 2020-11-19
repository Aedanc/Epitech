/*
** paladin.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 20:40:42 2017 Forteville Gabriel
** Last update Fri Jan 13 00:00:16 2017 Forteville Gabriel
*/

#ifndef __PALLADIN_HH_
#define __PALLADIN_HH_

#include "Priest.hh"
#include "Warrior.hh"

class Paladin : public Warrior, public Priest
{
    private:
        /*data*/
    public:
        Paladin(std::string const& name, int level);
        Paladin(Paladin const& other);
        ~Paladin();

        int CloseAttack();
        int RangeAttack();
        int Intercept();
        void heal();
        void Paladin::RestorePower()
};

#endif
