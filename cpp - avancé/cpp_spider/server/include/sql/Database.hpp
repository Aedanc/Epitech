//
// Database.hpp for Database in /home/guesti_a/Bureau/Tek3/cpp_spider
// 
// Made by Guestin Antoine
// Login   <guesti_a@epitech.net>
// 
// Started on  Tue Oct  3 13:26:20 2017 Guestin Antoine
// Last update Mon Oct  9 23:59:36 2017 nicolas
//

#ifndef		_DATABASE_HPP_
# define 	_DATABASE_HPP_

#include	<string>
#include <log.hpp>
#include	"mysql.hpp"

class		Database
{
public:
  Database();
  ~Database() {}
  bool		connect();
  bool		createEntry(std::string &str);
  bool		store(struct s_input &data, const unsigned int &id, std::map<unsigned char, std::string> &vkCodesMap);
  bool		expor(std::string Filename);
  bool		expor(std::string Filename, unsigned int id);
  bool		expor(std::string Filename, unsigned int id, std::string process);

 private:
  bool		exportDb(std::string query, std::string file);
  Mysql		mysql;
  std::string	DbName;
};

#endif		/* !_MYSQL_HPP_ */
