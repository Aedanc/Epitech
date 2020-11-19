/*
** SickKoala.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex02
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 09 14:04:47 2017 Forteville Gabriel
** Last update Mon Jan 09 22:11:42 2017 Forteville Gabriel
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
 this->name = name;
}

SickKoala::~SickKoala()
{
 std::cout << "Mr. " << this->name << ": Kreooogg!! Je suis gueriiii!" << std::endl;
}

void SickKoala::poke()
{
 std::cout << "Mr. " << this->name << ": Gooeeeeerrk!!: '(" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
 if (drug == "Buronzand")
  {
     std::cout << "Mr. " << this->name << ": Et la fatigue a fait son temps!" << std::endl;
     return 1;
  }
  std::transform(drug.begin(), drug.end(), drug.begin(), ::tolower);
  if (drug == "mars")
   {
     std::cout << "Mr. " << this->name << ": Mars, et ca kreog!" << std::endl;
     return 1;
   }
   std::cout << "Mr. " << this->name << ": Goerkreog!" << std::endl;
   return 0;
}

std::string SickKoala::getName()
{
    return this->name;
}

void SickKoala::overDrive(std::string str)
{
    size_t start_pos;
    while ((start_pos = str.find("Kreog!")) != std::string::npos)
      str.replace(start_pos, 6, "1337!");
    std::cout << "Mr. " << this->name << ": " << str << std::endl;
}
