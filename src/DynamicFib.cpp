#include <pybind11/pybind11.h>
#include "DynamicFib.h"
#include <stdexcept>

// namespace pbFunctions { namespace fib {

DynamicFib::DynamicFib()
    {
    }

// DynamicFib::DynamicFib()
    // {
    // remove();
    // }

int DynamicFib::compute(int n)
    {
    int f[n+2];
    int i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
        {
        f[i] = f[i-1] + f[i-2];
        }
    return f[n];
    }

// void export_DynamicFib(pybind11::module& m)
//     {
//     pybind11:class_< DynamicFib >(m, "DynamicFib")
//         .def(pybind11::init<>())
//         .def("compute", &DynamicFib::compute)
//         ;
//     }

// } } // end namespace pbFunctions::fib
