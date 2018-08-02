#include <pybind11/pybind11.h>

#include "DynamicFib.h"
#include "MatrixFib.h"
#include "fib.h"
#include "sqrtTrick.h"

namespace py = pybind11;

// using namespace pbFunctions::fib;

void exposeClasses(py::module m)
    {
    // this exposes a class from another c file here
    py::class_< DynamicFib >(m, "DynamicFib")
        .def(py::init<>())
        .def("compute", &DynamicFib::compute)
        ;
    // this exposes a function from another c file here
    m.def("spaceOptFib", &spaceOptFib);
    m.def("fastSqrt", &fastSqrt);
    m.def("invSqrt", &invSqrt);
    }

PYBIND11_MODULE(pbFunctions, m)
    {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    exposeClasses(m);
    // this will call a function that will export the c function within that file
    export_MatrixFib(m);
    }
