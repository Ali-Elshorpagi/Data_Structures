#ifndef BDEQUE_CPP
#define DEQUE_CPP

#include "../header/Deque.h"

template <class type>
Deque<type>::Deque(int sz) : size(sz)
{
    array = new type[size];
}

template <class type>
Deque<type>::~Deque()
{
    delete[] array;
    array = nullptr;
    size = added_elements = 0;
}

template <class type>
int Deque<type>::next(int pos)
{
    return (pos + 1) % size;
}

template <class type>
int Deque<type>::prev(int pos)
{
    return (pos - 1 + size) % size;
}

template <class type>
const int Deque<type>::get_size()
{
    return added_elements;
}

template <class type>
void Deque<type>::enqueue_rear(type val)
{
    assert(!is_full());
    array[rear] = val;
    rear = next(rear);
    ++added_elements;
}

template <class type>
void Deque<type>::enqueue_front(type val)
{
    assert(!is_full());
    front = prev(front);
    array[front] = val;
    ++added_elements;
}

template <class type>
type Deque<type>::dequeue_front()
{
    assert(!is_empty());
    type value(array[front]);
    front = next(front);
    --added_elements;
    return value;
}

template <class type>
type Deque<type>::dequeue_rear()
{
    assert(!is_empty());
    rear = prev(rear);
    type value(array[rear]);
    --added_elements;
    return value;
}

template <class type>
int Deque<type>::is_empty()
{
    return added_elements == 0;
}

template <class type>
bool Deque<type>::is_full()
{
    return added_elements == size;
}

template <class type>
void Deque<type>::print()
{
    std::cout << "Front " << front << " - rear " << rear << '\t';
    if (is_full())
        std::cout << "Full";
    else if (is_empty())
    {
        std::cout << "Empty" << edl << edl;
        return;
    }
    std::cout << edl;
    for (int cur(front), step(0); step < added_elements; ++step, cur = next(cur))
        std::cout << array[cur] << ' ';
    std::cout << edl << edl;
}
#endif