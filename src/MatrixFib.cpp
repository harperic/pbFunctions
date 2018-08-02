#include <pybind11/pybind11.h>
#include "MatrixFib.h"
#include <stdexcept>

// let's include an optional value to set the matrix size
MatrixFib::MatrixFib()
    {
    int n = 100;
    arrSize = n;
    // probably worth using the std::vec but we're super old school here
    // f = new int[n];
    f = new long[n];
    // this is necessary for the boolean check later
    // memset((void*)&f[0], 0, sizeof(int)*n);
    memset((void*)&f[0], 0, sizeof(long)*n);
    // use vector and standard libs
    // f = std::vector<int>(arrSize, 0);
    }

MatrixFib::MatrixFib(int n)
    {
    arrSize = n;
    // f = new int[n];
    f = new long[n];
    // this is necessary for the boolean check later
    // memset((void*)&f[0], 0, sizeof(int)*n);
    memset((void*)&f[0], 0, sizeof(long)*n);
    // use vector and standard libs
    // f = std::vector<int>(arrSize, 0);
    }

MatrixFib::~MatrixFib()
    {
    // only include if we are using the regular array
    delete[] f;
    }

// int MatrixFib::compute(int n)
long MatrixFib::compute(int n)
    {
    // resize the memory array if necessary
    if (arrSize < n+1)
        {
        // int* tmpF = new int[n+1];
        // memset((void*)tmpF, 0, sizeof(int)*(n+1));
        // memcpy((void*)tmpF, (void*)f, sizeof(int)*arrSize);

        long* tmpF = new long[n+1];
        memset((void*)tmpF, 0, sizeof(long)*(n+1));
        memcpy((void*)tmpF, (void*)f, sizeof(long)*arrSize);

        delete[] f;
        // std::vector<int> tmpF (n+1, 0);
        // std::copy(f.begin(), f.end(), tmpF.begin());
        arrSize = n+1;
        f = tmpF;
        }
    // set and return the initial array values
    if (n == 0)
        {
        f[n] = 0;
        return 0;
        }
    else if (n == 1)
        {
        f[n] = 1;
        return f[n];
        }

    if (f[n])
        return f[n];

    // this is actually a really cool line
    // (n & 1) is a very nice, cheap odd check
    // this is also a nice usage of ternary expressions
    // so if it's odd, return (n + 1)/2, otherwise n/2
    int k = (n & 1) ? (n + 1)/2 : n/2;

    f[n] = (n & 1) ? (compute(k)*compute(k) + compute(k-1)*compute(k-1)) : (2 * compute(k-1) + compute(k))*compute(k);

    return f[n];

    }

int MatrixFib::getArrSize()
    {
    return arrSize;
    }

void export_MatrixFib(pybind11::module& m)
    {
    pybind11::class_< MatrixFib >(m, "MatrixFib")
        .def(pybind11::init<>())
        .def(pybind11::init<int>())
        .def("compute", &MatrixFib::compute)
        ;
    }
