/*
** droid.hh for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d08/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 11 10:38:30 2017 Forteville Gabriel
** Last update Thu Jan 12 00:07:00 2017 Forteville Gabriel
*/

#ifndef __DROID_HH_
#define __DROID_HH_

#include <iostream>
#include "droidmemory.hh"

class Droid {

public:
    Droid(std::string id);
    Droid(const Droid & other);
    ~Droid();
    bool operator==(const Droid & other) const;
    bool operator!=(const Droid & other) const;
    void operator=(const Droid & other);
    size_t& operator<<(size_t &source);

    void setId(std::string id);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
    void setBattleData(DroidMemory *);

    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    const std::string* getStatus() const;
    const DroidMemory *getBattleData() const;

private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
    DroidMemory *_battleData;
}; /* Droid */

std::ostream& operator<<(std::ostream& os, Droid const& droid);

#endif /* __DROID_HH_ */
