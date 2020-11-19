//
// main.cpp for main in /home/dourches/Epitech/Seconde/Piscine/cpp_d17/ex00
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Fri Jan 20 10:07:56 2017 dourches
// Last update Fri Jan 20 10:25:19 2017 dourches
//

#include	<vector>
#include	<list>
#include	<iostream>
#include	<string>
#include	"find.hpp"

int main()
{
  int myints[] = {1, 2, 3, 4};
  std::vector<int> lol(myints, myints + sizeof(myints) / sizeof(int)); 
  std::list<int> xD(myints, myints + sizeof(myints) / sizeof(int)); 

  std::cout << *(do_find(lol, 2)) << std::endl;
  std::cout << *(do_find(xD, 4)) << std::endl;
  std::cout << *(do_find(xD, 6)) << std::endl;
  return 0;
}
