//
// Circuit.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/include
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 10 14:26:40 2016 Laurent QUERSIN
// Last update Sat Mar  4 00:44:07 2017 Laurent QUERSIN
//

#ifndef CIRCUIT_HPP__
# define CIRCUIT_HPP__

#include <string>
#include <map>
#include <algorithm>
#include <csignal>

#include "AComponent.hpp"
#include "Link.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Chipset4001.hpp"
#include "Chipset4008.hpp"
#include "Chipset4011.hpp"
#include "Chipset4030.hpp"
#include "Chipset4040.hpp"
#include "Chipset4069.hpp"
#include "Chipset4071.hpp"
#include "Chipset4081.hpp"
 
typedef AComponent *(action)(const std::string &);

bool sortFunc(const AComponent *, const AComponent *);

class Circuit
{
private:
  class CircuitImpl
  {
  public:
    CircuitImpl();
    ~CircuitImpl();
  
  private:
    bool					_continue;

    std::map<std::string, action*>		_factories;
    std::vector<AComponent*>			_inputs;
    std::vector<AComponent*>			_outputs;
    std::vector<AComponent*>			_clocks;
    std::vector<AComponent*>			_chipsets;

  public:
    int find(std::vector<AComponent*> &, const std::string &);
    void addComponentImpl(const std::string &, const std::string &);
  
    void setInputImpl(const std::string &, const nts::Tristate);
    void simulateImpl();
    void setLinkImpl(const std::string &, const size_t, const std::string &, const size_t);
    void sortCircuitImpl();
    void setDepth(const std::string &, AComponent &, size_t);
    void displayOutputsImpl();
    void dumpImpl();
    void loopImpl();
    void setContinueImpl(bool);
    
  private:
    nts::IComponent *getComponent(const std::string &);
    bool alreadyExists(const std::string &);
    void FlipClocks();
  };

public:
  Circuit();
  ~Circuit();

private:
  static CircuitImpl *getInstance();

public:
  void addComponent(const std::string &, const std::string &);
  void setInput(const std::string &, const nts::Tristate);
  void simulate();
  void setLink(const std::string &, const size_t, const std::string &, const size_t);
  void sortCircuit();
  void displayOutputs();
  void dump();
  void loop();
  void setContinue(bool);
};

void handleSigInt(int);

#endif
