#include <pybind11/pybind11.h>

int add(int a, int b){
    return a + b;
}

int increment_loop(int start, int end){
    int n = start;
    for(; n<end; n++){

    }
    return n;
}

PYBIND11_MODULE(adder, m){
    m.doc() = "fancy adder module";

    m.def("inc", &add, "add two variables");
}