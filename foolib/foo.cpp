#include "foo.h"

#include <iostream>
#include <vector>

// class FooSingle
// {
//   public:
//     static FooSingle* getInstance();
//     void foo()
//     {
//       std::cerr << "=== FooSingle::foo()" << std::endl;
//     }
//   private:
//     FooSingle()
//     {
//       std::cerr << "=== FooSingle this=" << (void*)this << std::endl;
//     }
// };
// 
// FooSingle* FooSingle::getInstance()
// {
//   static FooSingle* fs = 0;
//   if (fs == 0)
//   {
//     fs = new FooSingle();
//   }
//   std::cerr << "=== FooSingle getInstance() fs=" << (void*)fs << std::endl;
//   return fs;
// }

struct FooInitStruct
{
  FooInitStruct()
  :m_foo(123)
  {
    std::cerr << "=== libfoo: FooInit ctor " << (void*)this << " m_foo=" << m_foo << std::endl;
  }
  
  ~FooInitStruct()
  {
    std::cerr << "=== libfoo: FooInit dtor "<< (void*)this << "  m_foo=" << m_foo << std::endl;
    m_foo = 0;
  }
  
  int m_foo;  
};

FooInitStruct myInitStruct;

extern "C"
{

int foofunc(int i)
{
  int ret = i*i;
  std::cerr << "=== libfoo: foofunc(): i=" << i << " i*i=" << ret << std::endl;
//   FooSingle::getInstance()->foo();
  return ret;
}


}
