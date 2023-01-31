#include "..\\header\Deque.h"

template <class type>
Deque<type>::Deque(int sz) : size(sz)
{
    array = new type[size];
}

template <class type>
Deque<type>::~Deque()
{
    delete[] array;
}