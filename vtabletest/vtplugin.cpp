#include "pluginclasses.h"

#include <iostream>

extern "C"
{

int callme1(int i)
{
  int f = i*i;
  std::cerr << "--- " << "plugin1: callme1: i=" << i << " f=" << f << std::endl;
  std::cerr << "--- plugin: creating Base..." << std::endl;
  Base* b = new Derived();
  b->foo();
  b->bar();
  b->fump();
  delete b;

  return f;
}

}
