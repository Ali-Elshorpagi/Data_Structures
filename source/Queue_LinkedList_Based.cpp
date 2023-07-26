#ifndef QUEUE_LINKEDLIST_CPP
#define QUEUE_LINKEDLIST_CPP

#include "../header/Queue_LinkedList_Based.h"

template <class type>
Queue_LinkedList_Based<type>::Queue_LinkedList_Based() {}

template <class type>
Queue_LinkedList_Based<type>::~Queue_LinkedList_Based()
{
    list.~Singly_LinkedList();
    size = 0;
}

template <class type>
const int Queue_LinkedList_Based<type>::get_size()
{
    return size;
}

template <class type>
bool Queue_LinkedList_Based<type>::is_empty()
{
    return size == 0;
}

template <class type>
void Queue_LinkedList_Based<type>::enqueue(type val)
{
    list.insert_end(val);
    ++size;
}

template <class type>
type Queue_LinkedList_Based<type>::dequeue()
{
    --size;
    return list.pop_front();
}

template <class type>
void Queue_LinkedList_Based<type>::print()
{
    list.print();
}
#endif