#include <foo.h>

#include <iostream>

struct Plugin1InitStruct
{
  Plugin1InitStruct()
  {
    std::cerr << "--- " << "plugin1: Plugin1Init ctor " << (void*)this << std::endl;
  }

  ~Plugin1InitStruct()
  {
    std::cerr << "--- " << "plugin1: Plugin1Init dtor " << (void*)this << std::endl;
  }

} plugin1Init;

extern "C"
{

int callme1(int i)
{
  int f = foofunc(i+1);
  std::cerr << "--- " << "plugin1: callme1: i=" << i << " f=" << f << std::endl;
  return f;
}

}
