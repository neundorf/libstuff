#ifndef PLUGIN_CLASSES_H
#define PLUGIN_CLASSES_H


// #define EXPORT  __attribute__((visibility("hidden")))
#define EXPORT 

class EXPORT Base
{
  public:
    Base();
    virtual ~Base();
    virtual void foo();
    virtual void bar();
    void fump();
};


class EXPORT Derived : public Base
{
  public:
    Derived();
    virtual ~Derived();
    virtual void foo();
    virtual void bar();
};

#endif
