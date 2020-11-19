//
// TablePeNoel.cpp for  in /home/hurlu/rendu/cpp_santa
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 20:43:00 2017 Hugo Willaume
// Last update Sun Jan 15 08:38:45 2017 Hugo Willaume
//

#include <iostream>
#include <cstddef>
#include "TablePeNoel.hh"

TablePeNoel::TablePeNoel()
{
  for (int idx = 0; idx < 10; idx++)
    _table_array[idx] = NULL;
}

TablePeNoel::TablePeNoel(TablePeNoel const &other)
{
  for (int idx = 0; idx < 10; idx++)
    _table_array[idx] = other._table_array[idx]->clone();
}

TablePeNoel &TablePeNoel::operator=(TablePeNoel const &other)
{
  for (int idx = 0; idx < 10; idx++)
    _table_array[idx] = other._table_array[idx]->clone();
  return *this;
}

TablePeNoel::~TablePeNoel()
{
  for (int idx = 0; idx < 10; idx++)
    if (_table_array[idx] != NULL)
      delete _table_array[idx];
}

void TablePeNoel::Collapse()
{
  std::cout << "Table is collapsing, as well as all the objects on it !" << std::endl;
  std::cout << "Your program will probably Segfault shortly if you continue using the same table..." << std::endl;
  delete this;
}

std::string **TablePeNoel::Look() const
{
  std::string **titles = new std::string* [11];
  int idx_titles = 0;

  for (int idx = 0; idx < 10; idx++)
    if ( _table_array[idx] != NULL)
      {
	titles[idx_titles] = new std::string(_table_array[idx]->getTitle());
	idx_titles++;
      }
  titles[idx_titles] = NULL;
  return titles;
}

void TablePeNoel::Put(IObject* &obj)
{
  for (int idx = 0; idx < 10; idx++)
    {
      if (_table_array[idx] == NULL)
	{
	  std::swap(_table_array[idx], obj);
	  return;
	}
    }
  delete obj;
  Collapse();
}

IObject *TablePeNoel::Take()
{
  IObject *retval = NULL;

  std::swap(retval, _table_array[0]);
  for (int idx = 0; idx < 9; idx++)
    std::swap(_table_array[idx], _table_array[idx + 1]);
  return retval;
}

IObject *TablePeNoel::Take(int n)
{
  IObject *retval = NULL;

  if (_table_array[n] != NULL && n < 10)
    {
      std::swap(_table_array[n], retval);
      for (int idx = n; idx < 9; idx++)
	std::swap(_table_array[idx], _table_array[idx + 1]);
    }
  return retval;
}

IObject *TablePeNoel::TakeClass(std::string const filter, IObject *retval)
{
  bool swapmode = false;
  int idx = 0;

  for (idx = 0; idx < 9; idx++)
    {
      if (swapmode == false && _table_array[idx] != NULL
	  && filter == _table_array[idx]->getClass())
	{
	  std::swap(retval, _table_array[idx]);
	  swapmode = true;
	}
      if (swapmode == true)
	std::swap(_table_array[idx], _table_array[idx + 1]);
    }
  if (retval == NULL && _table_array[idx] != NULL
      && _table_array[idx]->getClass() == filter)
    std::swap(retval, _table_array[idx]);
  return retval;
}

IObject *TablePeNoel::TakeTitle(std::string const filter, IObject *retval)
{
  bool swapmode = false;
  int idx = 0;

  for (idx = 0; idx < 9; idx++)
    {
      if (swapmode == false && _table_array[idx] != NULL
	  && filter == _table_array[idx]->getTitle())
	{
	  std::swap(retval, _table_array[idx]);
	  swapmode = true;
	}
      if (swapmode == true)
	std::swap(_table_array[idx], _table_array[idx + 1]);
    }
  if (retval == NULL && _table_array[idx] != NULL
      && _table_array[idx]->getTitle() == filter)
    std::swap(retval, _table_array[idx]);
  return retval;
}

IObject *TablePeNoel::Take(std::string const filter, ITable::TakeFilter type)
{
  IObject *retval = NULL;

  if (type == ITable::BY_CLASS)
    return TakeClass(filter, retval);
  else if (type == ITable::BY_TITLE)
    return TakeTitle(filter, retval);
  return NULL;
}
