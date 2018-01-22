#include "pluginclasses.h"

#include <iostream>

Base::Base()
{
  std::cerr << "--- PLUGIN Base ctor" << std::endl;
}


Base::~Base()
{
  std::cerr << "--- PLUGIN Base dtor" << std::endl;
}


void Base::foo()
{
  std::cerr << "--- PLUGIN Base::foo()" << std::endl;
}


void Base::bar()
{
  std::cerr << "--- PLUGIN Base::bar()" << std::endl;
}


void Base::fump()
{
  std::cerr << "--- PLUGIN: Base::fump()" << std::endl;
}


Derived::Derived()
:Base()
{
  std::cerr << "--- PLUGIN Derived ctor" << std::endl;
}


Derived::~Derived()
{
  std::cerr << "--- PLUGIN Derived dtor" << std::endl;
}


void Derived::foo()
{
  std::cerr << "--- PLUGIN Derived::foo()" << std::endl;
}


void Derived::bar()
{
  std::cerr << "--- PLUGIN Derived::bar()" << std::endl;
}
