#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>
#include <cstdlib>

int increment_loop(int start, int end){
    int n = start;
    for (int i = start; i < end; i++){
        n = n+1;
    }
    return end;
}

PYBIND11_MODULE(adder, m){
    m.doc()="fancy adder module";
    m.def("increment_loop", &increment_loop, "add variables");
}