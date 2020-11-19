//
// Created by baldas on 10/6/17.
//

#include    <iostream>
#include    <cstring>
#include    "Parser/Parser.h"
#include    "misc/macros.h"

bool        Parser::parsePacket(void *data)
{
  char		*buffer;
  int		size;
  unsigned int	magic;
  t_input	input;

  buffer = reinterpret_cast<char *>(data);
  std::memcpy(&size, buffer, 4);
  buffer += 4;
  std::memcpy(&magic, buffer, 4);
  if (magic != 0xFFFFFFFF)
    return false;
  buffer += 4;
  for (int i = 0; i < size; i += sizeof(t_input))
    {
      std::memset(&input, 0, sizeof(t_input));
      std::memcpy(&input, buffer, sizeof(t_input));
      inputs.push_back(input);
      std::cout << "[Database] Inserting value into database" << std::endl;
      forStore.store(input, _id, _vkCodesMap);
      buffer += sizeof(t_input);
    }
  return true;
}

Parser::Parser(const int &id, std::map<unsigned  char, std::string> &vkCodesMap): _id(id),
										  _vkCodesMap(vkCodesMap)
{
  forStore.connect();
}
