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

template <class type>
void Priority_Queue<type>::enqueue(type val, ll priority)
{
	assert(!is_full());
	if (priority == 1)
		q1.enqueue(val);
	else if (priority == 2)
		q2.enqueue(val);
	else if (priority == 3)
		q3.enqueue(val);
	else
		assert(false); 
	++added_elements;
}

template <class type>
type Priority_Queue<type>::dequeue()
{
	assert(!is_empty());
	--added_elements;
	if (!q3.is_empty())
		return q3.dequeue();
	else if (!q2.is_empty())
		return q2.dequeue();
	else
		return q1.dequeue();
}