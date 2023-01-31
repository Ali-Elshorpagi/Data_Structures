#include "..\\header\Stack_Array_Based.h"

template <class type>
Stack_Array_Based<type>::Stack_Array_Based(unsigned long long sz) : size(sz), top(-1)
{
    arr = new type[size];
}

template <class type>
Stack_Array_Based<type>::~Stack_Array_Based()
{
    delete[] arr;
}
