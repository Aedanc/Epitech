/*
** Federation.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 11:03:44 2017 Forteville Gabriel
** Last update Tue Jan 10 12:58:33 2017 Forteville Gabriel
*/

#ifndef __FEDERATION_HH_
#define __FEDERATION_HH_

#include <iostream>
#include "WarpSystem.hh"

namespace Federation {

    class Ship {
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;

    public:
        Ship (int length, int width, std::string name);
        ~Ship ();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
    };

    namespace Starfleet {

        class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
	        WarpSystem::Core *_core;

        public:
            Ship (int length, int width, std::string name, short maxWarp);
            ~Ship ();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
        };

    }
}

#endif
