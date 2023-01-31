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
bool Circular_Queue<type>::is_empty()
{
    return added_elements == 0;
}

template <class type>
ll Circular_Queue<type>::get_size()
{
    return size;
}

template <class type>
ll Circular_Queue<type>::next(ll pos)
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
    type value = arr[front];
    front = next(front);
    --added_elements;
    return value;
}

template <class type>
void Circular_Queue<type>::print()
{
    cout << "Front " << front << " - rear " << rear << "\t";
    if (is_full())
        cout << "Full" << edl;
    else if (is_empty())
    {
        cout << "Empty" << edl << edl;
        return;
    }
    cout << edl;
    for (ll cur(front), step(0); step < added_elements; ++step, cur = next(cur))
        cout << arr[cur] << " ";
    cout << edl << edl;
}