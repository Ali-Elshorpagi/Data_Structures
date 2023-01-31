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

template <class type>
bool Stack_Array_Based<type>::is_full()
{
	return top == size - 1;
}

template <class type>
bool Stack_Array_Based<type>::is_empty()
{
	return top == -1;
}

template <class type>
void Stack_Array_Based<type>::push(type val)
{
	assert(!is_full());
	arr[++top] = val;
}

template <class type>
type Stack_Array_Based<type>::peek()
{
	assert(!is_empty());
	return arr[top];
}