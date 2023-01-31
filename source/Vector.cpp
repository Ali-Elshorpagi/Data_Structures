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

template <class type>
void Vector<type>::expand_capacity()
{
    capacity *= 2;
    type* arr2 = new type[capacity] {};
    for (ll i(0); i < size; ++i)
        arr2[i] = arr[i];
    swap(arr, arr2);
    delete[] arr2;
}
