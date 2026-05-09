#include <pybind11/detail/common.h>
# include <pybind11/pybind11.h>

int increment_loop(int start, int end){
    int n = start;
    for (int i =start; i< end; i++) {
        n = n+1;
    }
    return n;
}


PYBIND11_MODULE(adder, m) {
    m.doc() = "fancy adder module"; // Beachte: .doc() ist oft ein Attribut
    m.def("inc", &increment_loop, "add values in a loop");

}