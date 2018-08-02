#include <pybind11/pybind11.h>
#include "fib.h"

// namespace py{

int mf[100];

int spaceOptFib(int n)
    {
    int a = 0;
    int b = 1;
    int c, i;
    if (n < 0)
        {
        n = 0;
        }
    if (n == 0)
        {
        return a;
        }
    for (i = 2; i <= n; i++)
        {
        c = a + b;
        a = b;
        b = c;
        }
    return b;
    }

int recursiveFib(int n)
    {
    if (n <= 1)
        return n;
    return recursiveFib(n-1) + recursiveFib(n-2);
    }
// this isn't actually "recursive"
int dynamicFib(int n)
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

int matrixFib(int n)
    {
    if (n == 0)
        return 0;
    else if (n == 1)
        {
        mf[n] = 1;
        return mf[n];
        }
    else if (n == 2)
        {
        mf[n] = 1;
        return mf[n];
        }

    if (mf[n])
        return mf[n];

    int k = (n & 1) ? (n + 1)/2 : n/2;

    mf[n] = (n & 1) ? (matrixFib(k)*matrixFib(k) + matrixFib(k-1)*matrixFib(k-1)) : (2 * matrixFib(k-1) + matrixFib(k))*matrixFib(k);

    return mf[n];

    }

// void export_Fib(pybind11::module& m)
//         {
//         pybind11::class_< Fib >(m, "Fib")
//             // .def(pybind11::init<>())
//             .def("spaceOptFib", &spaceOptFib, "returns the nth fibonacci number");
//             .def("dynamicFib", &recursiveFib, "returns the nth fibonacci number");
//             .def("recursiveFib", &recursiveFib, "returns the nth fibonacci number");
//             .def("matrixFib", &recursiveFib, "returns the nth fibonacci number");
//         }
// }
