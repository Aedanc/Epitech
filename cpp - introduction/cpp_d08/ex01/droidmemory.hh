/*
** droidmemory.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d08/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 11 15:56:51 2017 Forteville Gabriel
** Last update Wed Jan 11 19:13:15 2017 Forteville Gabriel
*/

#ifndef __DROIDMEMORY_HH_
#define __DROIDMEMORY_HH_

#include  <iostream>

class DroidMemory {

    private:
        size_t _fingerPrint;
        size_t _exp;

    public:
        DroidMemory ();
        ~DroidMemory ();
        void setExp(size_t exp);
        void setFingerPrint(size_t fingerPrint);
        size_t getFingerPrint() const;
        size_t getExp() const;
        DroidMemory operator<<(DroidMemory const& source);
        DroidMemory operator>>(DroidMemory & dest);
        DroidMemory operator+=(DroidMemory const& source);
        DroidMemory operator+=(size_t const& source);
        DroidMemory operator+(DroidMemory const& source) const;
        DroidMemory operator+(size_t const& source) const;
}; /* DroidMemory */

std::ostream& operator<<(std::ostream& os, DroidMemory const& source);

#endif /* __DROIDMEMORY_HH_ */
