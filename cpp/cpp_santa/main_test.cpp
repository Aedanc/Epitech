//
// main_test.cpp for  in /home/hurlu/rendu/cpp_santa
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 16:40:18 2017 Hugo Willaume
// Last update Sun Jan 15 09:44:54 2017 Hugo Baldassin
//

#include <iostream>
#include "Box.hh"
#include "GiftPaper.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "TablePeNoel.hh"
#include "Elf.hh"
#include "ConveyorBelt.hh"
#include "unitTests.hh"

void ToysUnitTests()
{
  LittlePony *p1 = new LittlePony("p1");
  Teddy t1("t1");
  IObject *obj1 = new Teddy("toto");
  IObject **objs;

  std::cout << "Testing Toys objects..." << std::endl;
  std::cout << "=======================" << std::endl << std::endl;
  std::cout << "Pony isTaken() > ";
  p1->isTaken();
  std::cout << "Pony title is " << p1->getTitle() << std::endl; // p1
  std::cout << "Teddy isTaken() > ";
  t1.isTaken();
  std::cout << "Teddy title is " << t1.getTitle() << std::endl; // t1
  std::cout << "Object isTaken() > ";
  obj1->isTaken();
  std::cout << "Object title is " << obj1->getTitle() << std::endl; // obj1
  std::cout << std::endl;
  std::cout << "Calling the MyUnitTests() function..." << std::endl;
  objs = MyUnitTests();
  std::cout << "The array returned contains:" << std::endl;
  std::cout << "objs[0] = " << objs[0]->getClass() << ", " << objs[0]->getTitle() << std::endl;
  std::cout << "objs[1] = " << objs[1]->getClass() << ", " << objs[1]->getTitle() << std::endl;
  std::cout << std::endl;
  delete p1;
  delete obj1;
  delete objs[0];
  delete objs[1];
  delete[] objs;
}

void WrapUnitTests()
{
  IObject *p1 = new LittlePony("p1");
  IObject *t1 = new Teddy("t1");
  Box *b1 = new Box();
  GiftPaper *gp1 = new GiftPaper();

  std::cout << "Testing Wrap objects..." << std::endl;
  std::cout << "=======================" << std::endl;
  std::cout << std::endl << "The Box:" << std::endl;
  std::cout << "Box isOpen() && isEmpty() (expects 1, 1): " << b1->IsOpen() << " " << b1->IsEmpty() << std::endl; // 1
  std::cout << "Gift 1 : " << p1->getTitle() << std::endl;
  std::cout << "Wrapping in Box" << std::endl;
  b1->wrapMeThat(p1);
  std::cout << "Gift in the Box : " << b1->getGift()->getTitle() << std::endl;
  std::cout << "Box isOpen && isEmpty ? (expects 0, 0): " << b1->IsOpen() << " " << b1->IsEmpty() << std::endl; // 0
  std::cout << std::endl << "The Gift Paper:" << std::endl;
  std::cout << "Gift 2 : " << t1->getTitle() << std::endl;
  std::cout << "Wrapping in Gift Paper" << std::endl;
  gp1->wrapMeThat(t1);
  std::cout << "Gift in the Gift Paper : " << gp1->getGift()->getTitle() << std::endl;
  delete b1->getGift();
  delete gp1->getGift();
  delete b1;
  delete gp1;
}

ITable *CreateTable()
{
  return new TablePeNoel();
}

void PrintLook(std::string **look)
{
  int x = 0;
  for (x = 0; look[x] != NULL; x++)
    {
      std::cout << "\"" << *look[x] << "\" ";
      delete look[x];
    }
    delete[] look;
  std::cout << std::endl << std::endl;
}

void  TestElf()
{
  ITable *e = CreateTable();
  IConveyorBelt *z = new ConveyorBelt;
  Elf *elf = new Elf(e, z);
  Teddy *a = new Teddy("Mon petit Stéphane");
  IObject *b = new LittlePony("Epona pour les grands");
  GiftPaper *c = new GiftPaper();
  IObject *d = new Box();
  IObject *tmp;

  (void)a;
  (void)b;
  (void)c;
  (void)d;
  (void)e;
  (void)tmp;

  std::cout << std::endl;
  std::cout << "Testing Elf:" << std::endl;
  std::cout << "============" << std::endl << std::endl;
  elf->ElfWrap();
  std::cout << "Wrap test with a empty Table" << std::endl;
  std::cout << "if "", test successful" << std::endl;
  std::cout << std::endl;
  tmp = a->clone();
  e->Put(tmp); // Size : 1
  tmp = c->clone();
  e->Put(tmp); // Size : 2
  tmp = d->clone();
  e->Put(tmp); // Size : 3
  tmp = b->clone();
  e->Put(tmp); // Size : 4
  std::cout << "Wrap test with a Table full" << std::endl;
  std::cout << "if tuuuut tuuut tuut, test successful" << std::endl;
  elf->ElfWrap();
  std::cout << "Wrap Test if ConveyorBelt is already full" << std::endl;
  std::cout << "if "", test successful" << std::endl;
  z->put(tmp);
  PrintLook(e->Look());
  elf->ElfWrap();
  std::cout << "Test delete Elf" << std::endl;
  delete a;
  delete b;
  delete c;
  delete d;
  delete elf;
}

void TablePeUnitTests()
{
  Teddy *a = new Teddy("Mon petit Stéphane");
  IObject *b = new LittlePony("Epona pour les grands");
  GiftPaper *c = new GiftPaper();
  IObject *d = new Box();
  ITable *e = CreateTable();
  IObject *tmp;

  (void)a;
  (void)b;
  (void)c;
  (void)d;
  (void)e;
  (void)tmp;

  std::cout << std::endl;
  std::cout << "Testing Table:" << std::endl;
  std::cout << "==============" << std::endl << std::endl;
  tmp = a->clone();
  e->Put(tmp); // Size : 1
  tmp = c->clone();
  e->Put(tmp); // Size : 2
  tmp = d->clone();
  e->Put(tmp); // Size : 3
  tmp = c->clone();
  e->Put(tmp); // Size : 4
  tmp = c->clone();
  e->Put(tmp); // Size : 5
  tmp = b->clone();
  e->Put(tmp); // Size : 6
  tmp = d->clone();
  e->Put(tmp); // Size : 7
  tmp = c->clone();
  e->Put(tmp); // Size : 8
  tmp = d->clone();
  e->Put(tmp); // Size : 9
  tmp = d->clone();
  e->Put(tmp); // Size : 10
  //p = d->clone();
  std::cout << "Cette table à l'air pleine: vérifions son contenu..." << std::endl;
  PrintLook(e->Look());
  if (e == NULL)
    std::cout << "Table has collapsed, crap ! :( " << std::endl;
  std::cout << "Let's find our pony back in it..." << std::endl;
  tmp = e->Take(b->getTitle(), ITable::BY_TITLE); // Size : 9
  std::cout << "Retrieved " << tmp->getTitle() << std::endl;
  delete tmp;
  std::cout << "What about some gift wrap to go with it ? " << std::endl;
  tmp = e->Take(c->getClass(), ITable::BY_CLASS); // Size : 8
  std::cout << "Retrieved " << tmp->getClass() << std::endl;
  std::cout << "Let's look again at the table..." << std::endl;
  PrintLook(e->Look());
  std::cout << "I can also get the nth item of the item" << std::endl;
  delete tmp;
  tmp = e->Take(5);// Size : 7
  std::cout << "Retrieved " << tmp->getClass() << std::endl;
  delete tmp;
  std::cout << "Or the very first item." << std::endl;
  tmp = e->Take();// Size : 6
  std::cout << "Retrieved " << tmp->getTitle() << std::endl;
  std::cout << "How about we try to retrieve something that can't possibly be in there anymore? " << std::endl;
  PrintLook(e->Look());
  std::cout << "Let's try to get another Pony from this list that obviously does not contain one !" << std::endl;
  delete tmp;
  tmp = e->Take("Little Pony", ITable::BY_CLASS);
  std::cout << "Let's examine the pointer we got :\"" << tmp << "\" !" << std::endl;
  std::cout << "For the end, let's overflow our table !" << std::endl;
  delete tmp;
  tmp = a->clone();
  e->Put(tmp); // Size : 7
  tmp = c->clone();
  e->Put(tmp); // Size : 8
  tmp = d->clone();
  e->Put(tmp); // Size : 9
  tmp = c->clone();
  e->Put(tmp); // Size : 10
  tmp = c->clone();
  e->Put(tmp); //Overflow table;
  delete a;
  delete b;
  delete c;
  delete d;
  //  delete e; // On ne delete pas la table : Elle a été supprimée par le collapse
}

IConveyorBelt *CreateConveyorBelt()
{
  return new ConveyorBelt();
}

void ConveyorBeltUnitTests()
{
  IObject *toy = new Teddy("t1");
  AWrap *wrap;
  IConveyorBelt *cb = CreateConveyorBelt();

  std::cout << std::endl;
  std::cout << "Testing Conveyor Belt:" << std::endl;
  std::cout << "======================" << std::endl << std::endl;
  std::cout << "Creating a new Teddy 't1'" << std::endl;
  std::cout << "Pushing the in() button..." << std::endl;
  wrap = cb->in();
  std::cout << "We got a " << wrap->getClass() << std::endl;
  std::cout << "Wrapping the Teddy in the " << wrap->getClass() << std::endl;
  wrap->wrapMeThat(toy);
  std::cout << std::endl;
  std::cout << "Putting the item on the Conveyor Belt" << std::endl;
  cb->put((IObject*&)wrap);
  std::cout << "The item on the Conveyor Belt is " << ((AWrap*)cb->take())->getGift()->getTitle() << " in a " << cb->take()->getClass() << std::endl;
  std::cout << "Sending the Gift to Pepe Noel :D" << std::endl;
  cb->out();
  if (!cb->look())
    std::cout << "There is no more gifts on the Conveyor Belt." << std::endl;
  //  delete wrap; we don't have to free the wrap, he was eaten by the fat ugly Pepe noel when we called the out() func Call out() again if you want pepe Noel to eat your soul :D
  delete cb;
}

int main()
{
  ToysUnitTests();
  WrapUnitTests();
  TablePeUnitTests();
  ConveyorBeltUnitTests();
  TestElf();
  return 0;
}
