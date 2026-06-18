#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>



int increment_loop(int start, int end) {
    int n = start;
    for (int i = start; i < end; ++i) {
        n += 1;
    }
    return n;
}



PYBIND11_MODULE(adder, m) {
    m.doc() = "pyblind fancy adder module"; // optional module docstring
    
    m.def("increment_loop", &increment_loop, "A function which increments a loop");
}



