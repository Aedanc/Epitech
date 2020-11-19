/*
** Character.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 12:40:41 2017 Forteville Gabriel
** Last update Thu Jan 12 14:48:18 2017 Forteville Gabriel
*/

#ifndef __CHARACTER_HH_
#define __CHARACTER_HH_

#include <iostream>

class Character {
    protected:
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
        std::string _name;
        std::string _class;
        std::string _race;
        int _level;
        int _pv;
        int _power;

    public:
        Character (std::string const& name, int level);
        Character (Character const& other);
        ~Character ();

        enum attackRange { CLOSE,RANGE };
        attackRange Range;

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int _damage);

        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;

        Character operator=(Character const& other);
};


#endif
