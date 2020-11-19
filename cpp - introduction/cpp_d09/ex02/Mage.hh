/*
** Mage.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 12 15:58:32 2017 Forteville Gabriel
** Last update Thu Jan 12 18:17:41 2017 Forteville Gabriel
*/

#ifndef __MAGE_HH_
#define __MAGE_HH_

#include <iostream>
#include "Character.hh"

class Mage : public Character
{
        private:
            /* data */
        public:
            Mage (std::string const& name, int level);
            Mage (Mage const& other);
            ~Mage ();

            int CloseAttack();
            int RangeAttack();
            void RestorePower();
};

#endif
