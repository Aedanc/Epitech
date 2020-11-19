/*
** EventManager.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex02
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jan 19 14:21:13 2017 Gabriel Forteville
** Last update Thu Jan 19 21:43:21 2017 Gabriel Forteville
*/

#ifndef _EVENTMANAGER_H_
# define _EVENTMANAGER_H_

#include <list>
#include "Event.h"

class EventManager
{
 private:
  std::list<Event> _event;
  unsigned int _time;

 public:
  EventManager();
  ~EventManager();
  EventManager(EventManager const &);
  EventManager& operator=(EventManager const &);

  void addEvent(const Event&);

  void removeEventsAt(unsigned int);

  void dumpEvents(void) const;

  void dumpEventAt(unsigned int) const;

  void addTime(unsigned int);

  void addEventList(std::list<Event>&);
 };

#endif
