#include <stdlib.h>

#include <iostream>

#include <QDir>
#include <QLibrary>

// #define EXPORT  __attribute__((visibility("hidden")))
#define EXPORT 

class EXPORT Base
{
  public:
    Base() { std::cerr << "Base ctor" << std::endl; }
    virtual ~Base() { std::cerr << "Base dtor" << std::endl; }
    virtual void foo() { std::cerr << "Base::foo()" << std::endl; }
    virtual void bar() { std::cerr << "Base::bar()" << std::endl; }
};


class EXPORT Derived : public Base
{
  public:
    Derived() : Base() { std::cerr << "Derived ctor" << std::endl; }
    virtual ~Derived() { std::cerr << "Derived dtor" << std::endl; }
    virtual void foo() { std::cerr << "Derived::foo()" << std::endl; }
    virtual void bar() { std::cerr << "Derived::bar()" << std::endl; }
};


typedef int (*CallMeFunc)(int);

QLibrary* loadAndExecLib(const char* libname, const char* funcname, int value)
{
  std::cerr << "before loading " << libname << std::endl;
  QLibrary* lib = new QLibrary(QDir::currentPath() + "/libvtplugin.so");
  bool success = lib->load();
  CallMeFunc f1 = (CallMeFunc)lib->resolve(funcname);
  std::cerr << libname <<  " success: " << success << " f1: " << (void*)f1 << std::endl;
  
  if (success && f1)
  {
    f1(value);
  }
  
  return lib;
}
 

int main(int argc, char** argv)
{
  std::cerr << "main starts" << std::endl;

  if (argc != 2)
  {
    std::cerr << "argc=" << argc << "!" << std::endl;
    return -1;
  }

  Base* b = new Derived();
  b->foo();
  b->bar();
  

  QLibrary* p1 = loadAndExecLib("libp1", "callme1", 2);
  
  std::cerr << "before unload()" << std::endl;
  p1->unload();
  std::cerr << "after unload()" << std::endl;
  delete p1;

  delete b;
  b = 0;
  
  return 0;
  
}
