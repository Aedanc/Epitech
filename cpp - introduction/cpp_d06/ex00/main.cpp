//
// main.cpp for ex00 in /home/fortevg/rendu/piscine_cpp
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// Started on  Mon Jan  9 10:02:05 2017 Gabriel Forteville
// Last update Mon Jan  9 11:02:18 2017 Gabriel Forteville
//

#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char *av[])
{
  std::fstream file;

  if (ac == 1)
    {
      std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
      return 0;
    }
  for (int i = 1; i < ac; i++) {
    file.open(av[i]);
    if (file.is_open())
      {
	char c;
	while (file.get(c))
	  std::cout << c;
	file.close();
      }
    else
      std::cerr << "./" << av[0] << av[i] << ": No such file or directory" << std::endl;
  }
  return 0;
}
