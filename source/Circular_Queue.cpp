#include "..\\header\Circular_Queue.h"

template <class type>
Circular_Queue<type>::Circular_Queue(ll sz) : size(sz)
{
    arr = new type[size];
}

template <class type>
Circular_Queue<type>::~Circular_Queue()
{
    delete[] arr;
}
