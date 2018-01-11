#include <foo.h>

#include <stdio.h>

struct Plugin2InitStruct
{
  Plugin2InitStruct()
  {
    fprintf(stderr, "Plugin2Init ctor %p\n", this);
  }

  ~Plugin2InitStruct()
  {
    fprintf(stderr, "Plugin2Init dtor %p\n", this);
  }
  
} plugin2Init;

extern "C"
{

int callme2(int i)
{
  int f2 = foofunc(i+1);
  fprintf(stderr, "callme2: i=%d f=%d\n", f2);
  return f2;
}

}
