//
// Circuit.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/source
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 10 15:13:36 2016 Laurent QUERSIN
// Last update Sat Mar  4 00:42:48 2017 Laurent QUERSIN
//

#include "Circuit.hpp"

Circuit::CircuitImpl::CircuitImpl()
{
  _continue = true;
  _factories["input"] = CreateInput;
  _factories["output"] = CreateOutput;
  _factories["clock"] = CreateInput;
  _factories["link"] = CreateLink;
  _factories["4001"] = Create4001;
  _factories["4008"] = Create4008;
  _factories["4011"] = Create4011;
  _factories["4030"] = Create4030;
  _factories["4040"] = Create4040;
  _factories["4069"] = Create4069;
  _factories["4071"] = Create4071;
  _factories["4081"] = Create4081;
}

Circuit::CircuitImpl::~CircuitImpl()
{
  _factories.clear();
  _inputs.clear();
  _outputs.clear();
  _chipsets.clear();
  _clocks.clear();
}

int	Circuit::CircuitImpl::find(std::vector<AComponent*> &list, const std::string &str)
{
  std::vector<AComponent*>::iterator it;

  for (it = list.begin(); it != list.end(); ++it)
    {
      if ((*it)->getName() == str)
	return (std::distance(list.begin(), it));
    }
  return (-1);
}

bool Circuit::CircuitImpl::alreadyExists(const std::string &str)
{
  if (find(_inputs, str) != - 1)
    return (true);
  if (find(_outputs, str) != - 1)
    return (true);
  if (find(_clocks, str) != - 1)
    return (true);
  if (find(_chipsets, str) != - 1)
    return (true);

  return (false);
}

nts::IComponent* Circuit::CircuitImpl::getComponent(const std::string &str)
{
  size_t i = 0;
  
  if ((i = find(_inputs, str)) != - 1)
    return (_inputs[i]);
  if ((i = find(_outputs, str)) != - 1)
    return (_outputs[i]);
  if ((i = find(_clocks, str)) != - 1)
    return (_clocks[i]);
  if ((i = find(_chipsets, str)) != - 1)
    return (_chipsets[i]);
  return (NULL);
}

void Circuit::CircuitImpl::addComponentImpl(const std::string &type,
					    const std::string &name)
{
  if (alreadyExists(name) == true)
    throw ParsingError("addComponent: value " + name + "already exists.");
  if (_factories.find(type) == _factories.end())
    throw ParsingError("addComponent: unknown type: " + type);
  
  if (type == "input")
    _inputs.push_back(_factories[type](name));
  else if (type == "output")
    _outputs.push_back(_factories[type](name));
  else if (type == "clock")
    _clocks.push_back(_factories[type](name));
  else
    _chipsets.push_back(_factories[type](name));
}

void Circuit::CircuitImpl::setInputImpl(const std::string &name,
					const nts::Tristate state)
{
  size_t i;
  
  if ((i = find(_inputs, name)) != -1)
    _inputs[i]->SetState(state);
  if ((i = find(_clocks, name)) != -1)
    _clocks[i]->SetState(state);
}

void Circuit::CircuitImpl::setLinkImpl(const std::string &from, const size_t fpin, const std::string &to, const size_t tpin)
{
  nts::IComponent *fcmp;
  nts::IComponent *tcmp;
  
  if ((fcmp = getComponent(from)) == NULL)
    throw ParsingError("setLink: Component \"" + from + "\" does not exists.");
  if ((tcmp = getComponent(to)) == NULL)
    throw ParsingError("setLink: Component \"" + to + "\" does not exists.");
  fcmp->SetLink(fpin, *tcmp, tpin);
}

void Circuit::CircuitImpl::sortCircuitImpl()
{
  //sort les chipsets en partant des inputs pour définir la depth
  
  std::vector<AComponent*>::iterator it;
  
  for (it = _inputs.begin(); it != _inputs.end(); ++it)
    {
      setDepth((*it)->getName(),*(*it), 0);
    }
  std::sort(_chipsets.begin(), _chipsets.end(), sortFunc);
}

bool sortFunc(const AComponent *cmp1, const AComponent *cmp2)
{
  return (cmp1->depth < cmp2->depth);
}

void Circuit::CircuitImpl::setDepth(const std::string &name, AComponent &cmp, size_t depth)
{
  AComponent *link;
  size_t i = 0;

  if (cmp.lastVisitedBy == name)
    return;
  if (cmp.depth > depth)
    return;
  cmp.lastVisitedBy = name;
  cmp.depth = depth;
  while (i < cmp.depth)
    {
      if((link = cmp.getLinkedCmp(i)) != NULL)
	setDepth(name, *link, depth + 1);
      i++;
    }
}

void Circuit::CircuitImpl::simulateImpl()
{
  std::vector<AComponent *>::iterator it;
  size_t pin;
  nts::Tristate res;

  for (it = _chipsets.begin(); it != _chipsets.end(); ++it)
    {
      res = nts::Tristate::UNDEFINED;
      pin = 0;
      while (res != nts::Tristate::FALSE)
        res = (*it)->Compute(pin++);
    }
  FlipClocks();
}

void Circuit::CircuitImpl::FlipClocks()
{
  std::vector<AComponent *>::iterator it;

  for (it = _clocks.begin(); it != _clocks.end(); ++it)
    {
      if ((*it)->Compute(1) == nts::Tristate::TRUE)
        (*it)->SetState(nts::Tristate::FALSE);
      else if ((*it)->Compute(1) == nts::Tristate::FALSE)
	(*it)->SetState(nts::Tristate::TRUE);
    }
}

void Circuit::CircuitImpl::dumpImpl()
{
  std::vector<AComponent *>::iterator it;

  std::cout << "inputs:" << std::endl;
  for (it = _inputs.begin(); it != _inputs.end(); ++it)
    std::cout << "\t" << (*it)->getName() << std::endl;
  
  std::cout << "clocks:" << std::endl;
  for (it = _clocks.begin(); it != _clocks.end(); ++it)
    std::cout << "\t" << (*it)->getName() << std::endl;
  
  std::cout << "outputs:" << std::endl;
  for (it = _outputs.begin(); it != _outputs.end(); ++it)
    std::cout << "\t" << (*it)->getName() << std::endl;
  
  std::cout << "chipsets:" << std::endl;
  for (it = _chipsets.begin(); it != _chipsets.end(); ++it)
    {
      std::cout << "\t" << (*it)->getName() << std::endl;
      (*it)->Dump();
    }
}

void Circuit::CircuitImpl::displayOutputsImpl()
{
  std::vector<AComponent *>::iterator it;

  for (it = _outputs.begin(); it != _outputs.end(); ++it)
    {
      std::cout << (*it)->getName() << ": ";
      (*it)->Dump();
    }
}

void handleSigInt(int p)
{
  (void) p;
  Circuit c;
  
  c.setContinue(false);
}

void Circuit::CircuitImpl::loopImpl()
{
  std::signal(SIGINT, handleSigInt);
  while (_continue == true)
    {
      simulateImpl();
    }
  _continue = true;
  std::signal(SIGINT, SIG_DFL);
}

void Circuit::CircuitImpl::setContinueImpl(bool b)
{
  _continue = b;
}

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

Circuit::CircuitImpl *Circuit::getInstance()
{
  static Circuit::CircuitImpl *_instance = NULL;
  if (_instance == NULL)
    _instance = new CircuitImpl();
  return (_instance);
}


void Circuit::addComponent(const std::string &type, const std::string &name)
{
  getInstance()->addComponentImpl(type, name);
}

void Circuit::setInput(const std::string &str, const nts::Tristate state)
{
  getInstance()->setInputImpl(str, state);
}

void Circuit::simulate()
{
  getInstance()->simulateImpl();
}

void Circuit::setLink(const std::string &from, const size_t fpin, const std::string &to, const size_t tpin)
{
  getInstance()->setLinkImpl(from, fpin, to, tpin);
}

void Circuit::sortCircuit()
{
  getInstance()->sortCircuitImpl();
}

void Circuit::displayOutputs()
{
  getInstance()->displayOutputsImpl();
}

void Circuit::dump()
{
  getInstance()->dumpImpl();
}

void Circuit::loop()
{
  getInstance()->loopImpl();
}

void Circuit::setContinue(bool b)
{
  getInstance()->setContinueImpl(b);
}
