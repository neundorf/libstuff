
#include <iostream>

// #define EXPORT  __attribute__((visibility("hidden")))
#define EXPORT 

class EXPORT Base
{
  public:
    Base() { std::cerr << "--- PLUGIN Base ctor" << std::endl; }
    virtual ~Base() { std::cerr << "--- PLUGIN Base dtor" << std::endl; }
    virtual void foo() { std::cerr << "--- PLUGIN Base::foo()" << std::endl; }
    virtual void bar() { std::cerr << "--- PLUGIN Base::bar()" << std::endl; }
};


class EXPORT Derived : public Base
{
  public:
    Derived() : Base() { std::cerr << "--- PLUGIN Derived ctor" << std::endl; }
    virtual ~Derived() { std::cerr << "--- PLUGIN Derived dtor" << std::endl; }
    virtual void foo() { std::cerr << "--- PLUGIN Derived::foo()" << std::endl; }
    virtual void bar() { std::cerr << "--- PLUGIN Derived::bar()" << std::endl; }
};


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
  delete b;

  return f;
}

}
