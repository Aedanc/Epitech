//
// Created by baldas on 10/6/17.
//

#ifndef     CPP_SPIDER_PARSER_H
# define    CPP_SPIDER_PARSER_H

# include   <list>
#include <sql/Database.hpp>
# include   "misc/t_input.h"

class       Parser {
public:
    Parser(const int &id, std::map<unsigned  char, std::string> &vkCodesMap);
    ~Parser() = default;

  bool        parsePacket(void *data);

  Database	forStore;
  const unsigned int 		&_id;
  std::map<unsigned  char, std::string> &_vkCodesMap;
  std::list<t_input> inputs;
};

#endif      // !CPP_SPIDER_PARSER_H
