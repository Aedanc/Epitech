/*
** WarpSystem.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 11:51:28 2017 Forteville Gabriel
** Last update Tue Jan 10 12:19:31 2017 Forteville Gabriel
*/

#ifndef __WARPSYSTEM_HH_
#define __WARPSYSTEM_HH_

#include <iostream>

namespace WarpSystem{

    class QuantumReactor {
    private:
        bool _stability;

    public:
        QuantumReactor ();
        ~QuantumReactor ();

        bool isStable();
        void setStability(bool stability);
    };

    class Core {
    private:
        QuantumReactor *_coreReactor;

    public:
        Core (QuantumReactor *coreReactor);
        ~Core ();
        QuantumReactor *checkReactor();
    };
}

#endif
