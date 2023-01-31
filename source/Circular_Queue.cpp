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


template <class type>
bool Circular_Queue<type>::is_full()
{
	return added_elements == size;
}

template <class type>
bool  Circular_Queue<type>::is_empty() 
{
	return added_elements == 0;
}
