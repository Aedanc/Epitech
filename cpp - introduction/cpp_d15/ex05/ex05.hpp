//
// ex05.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex05
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 15:27:40 2017 Gabriel Forteville
// Last update Thu Jan 19 10:05:41 2017 Gabriel Forteville
//

#include <iostream>
#include <exception>

template <typename T>
class array
{
private:
  unsigned int _size;

public:
  T *_array;

  array(unsigned int size = 0)
  {
    _array = new T[size];
    _size = size;
    for (unsigned int i = 0; i < _size; i++)
      _array[i] = T();
  }

  ~array()
  {
    delete[] _array;
  }

  array(array const& other)
  {
    _array = new T[other._size];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
      _array[i] = other[i];
  }


  array const& operator=(array const& other)
  {
    if (this == &other)
      return *this;
    delete[] _array;
    _array = new T[other._size];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
      _array[i] = other._array[i];
    return *this;
  }

  T &  operator[](unsigned int const& index) const
  {
    if (index + 1 > _size)
      throw std::exception();
    return _array[index];
  }

  T &  operator[](unsigned int const& index)
  {
    T *result;
    unsigned int i;

    if (index + 1 > _size)
      {
	result = new T[index + 1];
        for (i = 0; i < _size; i++)
	  result[i] = _array[i];
	for (; i <= index; i++)
	  result[i] = T();
	  delete[] _array;
	_array = result;
	_size = index + 1;
      }
    return _array[index];
  }

  unsigned int size() const
  {
    return _size;
  }

  void dump() const
  {
    unsigned int i;

    std::cout << "[";
    for (i = 0; i < _size; i++)
      {
	std::cout << std::boolalpha << _array[i];
	if (i != _size - 1)
	  std::cout << ", ";
      }
    std::cout << "]" << std::endl;
  }

  template <typename U>
  array<U> convertTo(U (*convert)(T const &))
  {
    array<U> result(_size);

    delete[] result._array;
    result._array = new U[_size];
    for (unsigned int i = 0; i < _size; i++)
      result[i] = convert(_array[i]);
    return result;
  }
};
