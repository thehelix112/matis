#include <iostream>
#include <dlfcn.h>

#define RTLD_NEXT ((void *) -1l)

int main() {
    using std::cout;
    using std::cerr;

    cout << "C++ dlopen demo\n\n";

    // open the library
    cout << "Opening hello.so...\n";
    void* handle = dlopen("./hello.so", RTLD_LAZY);
    
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    
    // load the symbol
    cout << "Loading symbol hello...\n";
    typedef void (*hello_t)();
    hello_t hello = (hello_t) dlsym(handle, "hello");
    if (!hello) {
        cerr << "Cannot load symbol 'hello': " << dlerror() <<
            '\n';
        dlclose(handle);
        return 1;
    }
    
    // use it to do the calculation
    cout << "Calling hello...\n";
    hello();
    
    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}
