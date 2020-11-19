//
// EventManager.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex02
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Thu Jan 19 14:43:24 2017 Gabriel Forteville
// Last update Thu Jan 19 20:37:05 2017 Gabriel Forteville
//

#include <iostream>
#include "EventManager.h"

EventManager::EventManager() {
  _time = 0;
}

EventManager::~EventManager() {}

EventManager::EventManager(EventManager const & other)
{
  _event = other._event;
  _time = 0;
}

EventManager& EventManager::operator=(EventManager const & other)
{
  _event = other._event;
  _time = 0;
  return *this;
}

void EventManager::addEvent(const Event & event)
{
  std::list<Event>::iterator  it;

  if (event.getTime() < _time)
    return;
  it = _event.begin();
  while (it != _event.end() && event.getTime() >= it->getTime())
    it++;
  _event.insert(it, event);
}

void EventManager::removeEventsAt(unsigned int at)
{
  std::list<Event>::iterator  it;

  for (it =_event.begin(); it != _event.end(); it++)
    {
      if (it->getTime() == at)
	  _event.erase(it--);
    }
}

void EventManager::dumpEvents(void) const
{
  std::list<Event>::const_iterator  it;

  it = _event.begin();
  while (it != _event.end())
    {
      std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
      it++;
    }
}

void EventManager::dumpEventAt(unsigned int at) const
{
  std::list<Event>::const_iterator  it;

  it =_event.begin();
  while (it != _event.end())
    {
      if (it->getTime() == at)
	std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
      it++;
    }
}

void EventManager::addTime(unsigned int add)
{
  std::list<Event>::iterator  it;

  _time += add;
  it = _event.begin();
  while (it != _event.end() && it->getTime() <= _time)
    {
      std::cout  << it->getEvent() << std::endl;
      it++;
      _event.pop_front();
    }
}

void EventManager::addEventList(std::list<Event>& list)
{
  std::list<Event>::iterator  it;

  for (it = list.begin(); it != list.end(); it++)
    addEvent(*it);
}
