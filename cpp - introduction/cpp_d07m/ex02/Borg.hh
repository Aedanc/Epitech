/*
** Borg.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 13:33:48 2017 Forteville Gabriel
** Last update Tue Jan 10 16:21:32 2017 Forteville Gabriel
*/

#ifndef __BORG_HH_
#define __BORG_HH_

#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Borg {

    class Ship {
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;

        public:
            Ship ();
            ~Ship ();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d); // move _location to d
            bool move(int warp); // move _location to _home
            bool move(Destination d); // move _location to d
            bool move(); // move _location to _home
    };


} /* Borg */

#endif
