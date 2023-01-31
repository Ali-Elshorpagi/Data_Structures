#include "..\\header\Queue_LinkedList_Based.h"

template <class type>
Queue_LinkedList_Based<type>::Queue_LinkedList_Based()
{
}

template <class type>
Queue_LinkedList_Based<type>::~Queue_LinkedList_Based()
{
}

template <class type>
bool Queue_LinkedList_Based <type>::is_empty() 
{
	return list.get_length == 0;
}

template <class type>
void Queue_LinkedList_Based <type>::enqueue(type val)
{
	list.insert_end(val);
}