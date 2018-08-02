#include <pybind11/pybind11.h>

/* namespace py = pybind11; */

int spaceOptFib(int n);

int dynamicFib(int n);

int recursiveFib(int n);

int matrixFib(int n);

/* PYBIND11_MODULE(example, m) */
/*     { */
/*     m.doc() = "pybind11 example plugin"; // optional module docstring */
/*     m.def("spaceOptFib", &spaceOptFib, "returns the nth fibonacci number"); */
/*     m.def("dynamicFib", &recursiveFib, "returns the nth fibonacci number"); */
/*     m.def("recursiveFib", &recursiveFib, "returns the nth fibonacci number"); */
/*     m.def("matrixFib", &recursiveFib, "returns the nth fibonacci number"); */
/*     } */
/* void export_Fib(pybind11::module& m); */
