#include <pybind11/pybind11.h>

int add(int a, int b) { return a + b; }

int increment_loop(int start, int end) {
  int n = start;
  for (int i = start; i < end; i++) {
    n = n + 1;
  }
  return n;
}

PYBIND11_MODULE(adder, m) {
  m.doc() = "fancy adder module";

  m.def("add", &add, "A function which adds two numbers");
  m.def("inc", &increment_loop,
        "A function which increments a value in a loop");
}