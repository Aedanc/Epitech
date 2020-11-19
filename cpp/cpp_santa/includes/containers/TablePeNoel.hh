//
// TablePeNoel.hh for  in /home/hurlu/rendu/cpp_santa/containers
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 18:55:52 2017 Hugo Willaume
// Last update Sun Jan 15 02:23:43 2017 Hugo Willaume
//

#ifndef		TABLE_PE_NOEL_HH_
# define	TABLE_PE_NOEL_HH_

# include "ITable.hh"
# include "IObject.hh"

class TablePeNoel : public ITable{
private:
  IObject* _table_array[10];
  virtual IObject *TakeTitle(std::string, IObject *);
  virtual IObject *TakeClass(std::string, IObject *);

protected:
  virtual void Collapse();

public:

  TablePeNoel();
  TablePeNoel(TablePeNoel const &other);
  TablePeNoel &operator=(TablePeNoel const &other);
  ~TablePeNoel();

  virtual std::string **Look() const;
  virtual void Put(IObject* &obj);
  virtual IObject *Take();
  virtual IObject *Take(int n);
  virtual IObject *Take(std::string filter, ITable::TakeFilter type);
};

#endif		/* TABLE_PE_NOEL_HH */
