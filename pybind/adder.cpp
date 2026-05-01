# include <pybind11/detail/common.h> // added by itself, but I am kind-hearted, so I let it live here
# include <pybind11/pybind11.h>

int increment_loop ( int start, int end){
    int n = 0;
    for (int i = start; i < end; i++){
        n = n + 1;
    }
    return n;
}

int add(int a, int b){
    return a + b;
}

PYBIND11_MODULE(adder, m) { // because of the version pybind11::mod_gll_not_used() is not used. Earlier version had to use that
    m.doc() = "fancy adder module";
    m.def("add", &add, "A function that adds two numbers"); // "add" can be whatever name I want it to be
    m.def("increment", &increment_loop, "A function that adds two numbers");
}