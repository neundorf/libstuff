#include <stdlib.h>

#include <iostream>

#include <QDir>
#include <QLibrary>

#include <foo.h>

typedef int (*CallMeFunc)(int);

QLibrary* loadAndExecLib(const char* libname, const char* funcname, int value)
{
  std::cerr << "before loading " << libname << std::endl;
  QLibrary* lib = new QLibrary(QDir::currentPath() + "/libp1.so");
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

  int value = atoi(argv[1]);

  std::cerr << "hello !" << std::endl;
  int f = foofunc(value);
  std::cerr << "value=" << value << " f=" << f << std::endl;

  QLibrary* p1 = loadAndExecLib("libp1", "callme1", value);
  
  std::cerr << "before unload()" << std::endl;
  p1->unload();
  std::cerr << "after unload()" << std::endl;
  delete p1;
  
  return 0;
  
}
