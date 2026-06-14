#include "base.hpp"
#include "derived.hpp"

int main(){
    Base base;
    Derived derived;

    base.whoami();
    base.whoami();

    derived.whoami(); //has the same function, because it is derived from base
    derived.whoami();

    Derived copy = derived;

    derived.whoami();
    copy.whoami();

    Derived *p_derived = new Derived();
    p_derived->whoami();

    Base *p_base = new Base();
    //Base *p_base = p_derived; // takes parameters from  derived, but uses functions only from p_base. 
    // It's like taking only the part, which derived got from base. But the functions are from base
    // virtual fixes the problem, when there is I am Base statt I am Derived
    // override is not that important, because for compiler virtual says everything, what's needed.
    // override shows the intention of a programmer and will work without virtual 
    
    p_base->whoami();

    Derived *maybe = dynamic_cast<Derived*>(p_base); // if p_base = new Base() -> will not function
    
    if (maybe == nullptr) { // because it's a pointer
        std::cout << "can't convert\n";
    } else{
        maybe->hello();
    }

    return 0;
}
