#include "foo.h"

#include <iostream>
#include <vector>

#ifdef STATIC
#  define LIB_TYPE_STRING "STATIC"
#else
#  define LIB_TYPE_STRING "SHARED"
#endif

struct FooInitStruct
{
  FooInitStruct()
  :m_foo(123)
  {
    std::cerr << "=== " LIB_TYPE_STRING " libfoo: FooInit ctor " << (void*)this << " m_foo=" << m_foo << std::endl;
  }
  
  ~FooInitStruct()
  {
    std::cerr << "=== " LIB_TYPE_STRING " libfoo: FooInit dtor "<< (void*)this << "  m_foo=" << m_foo << std::endl;
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
