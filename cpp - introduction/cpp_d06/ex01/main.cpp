//
// main.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d06/ex01
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// Started on  Mon Jan  9 11:09:59 2017 Gabriel Forteville
// Last update Mon Jan  9 11:17:25 2017 Gabriel Forteville
//

#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
  float value;
  std::string unit;
  float result;

  std::cin >> value;
  std::cin >> unit;
  if (unit == "Fahrenheit")
  {
    result = (5.0 / 9.0) * (value - 32);
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Celsius" << std::endl;
  }
  if (unit == "Celsius")
  {
    result = (((value * 9) / 5) + 32);
    std::cout << std::setw(16) << std::fixed << std::setprecision (3) << result << std::setw(16) << "Fahrenheit" << std::endl;
  }

  return 0;
}
