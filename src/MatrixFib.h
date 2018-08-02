#include <pybind11/pybind11.h>

class MatrixFib
    {
public:
    MatrixFib();
    MatrixFib(int n);
    ~MatrixFib();

    /* int compute(int n); */
    long compute(int n);
    int getArrSize();
    /* void setArrSize(int n); */

private:
    // I don't recall if this is the correct way to do this
    /* int *f; */
    long *f;
    /* std::vector<int> f; */
    int arrSize;

    };

void export_MatrixFib(pybind11::module& m);

