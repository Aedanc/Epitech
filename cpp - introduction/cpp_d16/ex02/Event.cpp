//
// Event.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex02
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Thu Jan 19 11:27:48 2017 Gabriel Forteville
// Last update Thu Jan 19 19:45:14 2017 Gabriel Forteville
//

#include "Event.h"

Event::Event(unsigned int time, std::string event):
  _time(time),
  _event(event)
{}

Event::Event(Event const& other):
  _time(other._time),
  _event(other._event)
{}

Event::~Event() {}

void Event::setTime(unsigned int time) { _time = time; }

void Event::setEvent(std::string event) { _event = event; }

unsigned int Event::getTime() const { return _time; }

const std::string & Event::getEvent() const { return _event; }

Event & Event::operator=(Event const& other)
{
  _time = other._time;
  _event = other._event;
  return *this;
}
