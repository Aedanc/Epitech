/*
1;2802;0c** Event.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex02
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jan 19 11:08:09 2017 Gabriel Forteville
** Last update Fri Jan 20 09:08:48 2017 Gabriel Forteville
*/

#ifndef _EVENT_H_
# define _EVENT_H_

# include <string>

class Event
{
 private:
  unsigned int _time;
  std::string _event;

 public:
  Event(unsigned int time, std::string event);
  Event(Event const& other);
  ~Event();

  void setTime(unsigned int time);
  void setEvent(std::string event);
  unsigned int getTime() const;
  const std::string & getEvent() const;

  Event & operator=(Event const& other);
};
#endif
