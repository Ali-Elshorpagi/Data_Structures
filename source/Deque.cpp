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

template <class type>
ll Deque<type>::next(ll pos)
{
	return (pos + 1) % size;
}

template <class type>
ll Deque<type>::prev(ll pos)
{
	return (pos - 1 + size) % size;
}

template <class type>
void Deque<type>::enqueue_rear(type val)
{ 
	assert(!is_full());
	array[rear] = val;
	rear = next(rear);
	++added_elements;
}