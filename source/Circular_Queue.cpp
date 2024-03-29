#ifndef CIRCULAR_QUEUE_CPP
#define CIRCULAR_QUEUE_CPP

#include "../header/Circular_Queue.h"

template <class type>
Circular_Queue<type>::Circular_Queue(int sz) : size(sz)
{
    arr = new type[size];
}

template <class type>
Circular_Queue<type>::~Circular_Queue()
{
    delete[] arr;
    arr = nullptr;
    size = added_elements = 0;
}

template <class type>
bool Circular_Queue<type>::is_full()
{
    return added_elements == size;
}

template <class type>
bool Circular_Queue<type>::is_empty()
{
    return added_elements == 0;
}

template <class type>
const int Circular_Queue<type>::get_size()
{
    return size;
}

template <class type>
int Circular_Queue<type>::next(int pos)
{
    return (pos + 1) % size;
}

template <class type>
void Circular_Queue<type>::enqueue(type val)
{
    assert(!is_full());
    arr[rear] = val;
    rear = next(rear);
    ++added_elements;
}

template <class type>
type Circular_Queue<type>::dequeue()
{
    assert(!is_empty());
    type value(arr[front]);
    front = next(front);
    --added_elements;
    return value;
}

template <class type>
void Circular_Queue<type>::print()
{
    std::cout << "Front " << front << " - Rear " << rear << '\t';
    if (is_full())
        std::cout << "Full" << edl;
    else if (is_empty())
    {
        std::cout << "Empty" << edl << edl;
        return;
    }
    std::cout << edl;
    for (int cur(front), step(0); step < added_elements; ++step, cur = next(cur))
        std::cout << arr[cur] << ' ';
    std::cout << edl << edl;
}
#endif