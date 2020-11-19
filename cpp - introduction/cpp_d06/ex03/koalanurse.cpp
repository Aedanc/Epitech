/*
** koalanurse.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 09 16:47:11 2017 Forteville Gabriel
** Last update Tue Jan 10 09:57:42 2017 Forteville Gabriel
*/

#include <string>
#include <iostream>
#include <fstream>

#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
    this->workNow = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Enfin un peu de repos!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string name)
{
    std::string drug = "";
    std::fstream file;
    std::string fileName = name;

    fileName += ".report";
    file.open(fileName.c_str());
    if(file.is_open()) {
        file >> drug;
            file.close();
            std::cout << "Nurse " << this->id << ": Kreog! Il faut donner un " << drug << " a Mr." << name << "!" << std::endl;
        }
    return drug;
}

void KoalaNurse::timeCheck()
{
    if (this->workNow == false)
        {
            this->workNow = true;
            std::cout << "Nurse " << this->id << ": Je commence le travail!" << std::endl;
        }
    else
    {
        this->workNow = false;
        std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
    }
}
