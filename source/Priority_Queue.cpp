#include "..\\header\Priority_Queue.h"

template <class type>
Priority_Queue<type>::Priority_Queue(ll sz) : size(sz), q1(sz), q2(sz), q3(sz)
{
}

template <class type>
Priority_Queue<type>::~Priority_Queue()
{
}

template <class type>
bool Priority_Queue<type>::is_empty()
{
	return added_elements == 0;
}

template <class type>
bool Priority_Queue<type>::is_full()
{
	return added_elements == size;
}