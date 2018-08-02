#include <pybind11/pybind11.h>

/* namespace pbFunctions { namespace fib { */

class DynamicFib
    {
public:
    DynamicFib();
    /* ~DynamicFib(); */

    int compute(int n);

    /* private: */

    };

/* void export_DynamicFib(pybind11::module& m); */

/* } } // end namespace pbFunctions::fib */
