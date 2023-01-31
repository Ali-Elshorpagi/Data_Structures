#include "..\\header\Vector.h"

template <class type>
Vector<type>::Vector(ll sz)
{
    size = sz;
    if (size < 0)
        size = 1;
    capacity = size + 10;
    arr = new type[capacity] {};
}

template <class type>
Vector<type>::~Vector()
{
    delete[] arr;
    arr = nullptr;
}
