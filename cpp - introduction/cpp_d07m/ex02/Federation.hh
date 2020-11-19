/*
** Federation.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 11:03:44 2017 Forteville Gabriel
** Last update Tue Jan 10 16:23:10 2017 Forteville Gabriel
*/

#ifndef __FEDERATION_HH_
#define __FEDERATION_HH_

#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Federation {

    class Ship {
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;

    public:
        Ship (int length, int width, std::string name);
        ~Ship ();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d); // move _location to d
        bool move(int warp); // move _location to _home
        bool move(Destination d); // move _location to d
        bool move(); // move _location to _home
    };

    namespace Starfleet {

        class Captain {
        private:
            std::string _name; //given during construction
            int _age; //not given during construction

        public:
            Captain (std::string name);
            ~Captain ();
             std::string getName();
             int getAge();
             void setAge(int);
        }; /*Captain*/

        class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
	        WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;

        public:
            Ship (int length, int width, std::string name, short maxWarp);
            ~Ship ();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain*);
            bool move(int warp, Destination d); // move _location to d
            bool move(int warp); // move _location to _home
            bool move(Destination d); // move _location to d
            bool move(); // move _location to _home
        }; /*Ship*/

        class Ensign {
        private:
            std::string _name;

        public:
            explicit Ensign (std::string name);
            ~Ensign ();

        };
    }
}

#endif
