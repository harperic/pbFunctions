#include <pybind11/pybind11.h>
#include "sqrtTrick.h"
#include <math.h>

float fastSqrt(float x)
    {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
    }

float invSqrt(float x)
    {
    return 1.0f/sqrt(x);
    }
