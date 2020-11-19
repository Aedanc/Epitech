//
// GiftPaper.hh for  in /home/hurlu/rendu/cpp_santa/includes
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 13:58:13 2017 Hugo Willaume
// Last update Sat Jan 14 22:40:52 2017 Hugo Willaume
//

#ifndef		GIFT_PAPER_HH_
# define	GIFT_PAPER_HH

#include "AWrap.hh"

class GiftPaper : public AWrap{
private:


protected:


public:
  GiftPaper();
  GiftPaper(GiftPaper const &other);
  GiftPaper & operator=(GiftPaper const &other);
  ~GiftPaper();

  virtual void wrapMeThat(IObject* &);
  virtual IObject *clone() const;
};

#endif		/* GIFT_PAPER_HH */
