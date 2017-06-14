#include <dlfcn.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class A
{

public:
    static void printMe()
    {
    
        cout << "hi" << endl;
        
    };
    
};

extern "C" void *malloc(size_t size)
{
  static void * (*func)(size_t);

  if(!func)
    func = (void *(*)(size_t)) dlsym(RTLD_NEXT, "malloc");

  A::printMe();
  
  //std::cout << "malloc(" << size << ") called\n";
  

  printf("malloc(%d) is called\n", size);     

  return(func(size));
};

