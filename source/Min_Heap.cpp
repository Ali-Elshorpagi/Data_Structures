#include "..\\header\Min_Heap.h"

template <class type>
Min_Heap<type>::Min_Heap()
{
    array = new type[capacity]{};
    size = 0;
}

template <class type>
Min_Heap<type>::Min_Heap(const vector<type> &vec)
{
    assert((int)vec.size() <= capacity);
    array = new type[capacity]{};
    size = vec.size();
    for (int i(0); i < (int)vec.size(); ++i)
        array[i] = vec[i];
    heapify();
}

template <class type>
Min_Heap<type>::~Min_Heap()
{
    delete[] array;
    array = nullptr;
}

template <class type>
int Min_Heap<type>::left(int pos)
{
    int p((pos << 1) + 1);
    return p >= size ? -1 : p;
}

template <class type>
int Min_Heap<type>::right(int pos)
{
    int p((pos << 1) + 2);
    return p >= size ? -1 : p;
}

template <class type>
int Min_Heap<type>::parent(int pos)
{
    return pos == 0 ? -1 : ((pos - 1) >> 1);
}

template <class type>
void Min_Heap<type>::heapify_up(int child_pos)
{
    int par_pos(parent(child_pos));
    if (!child_pos || array[par_pos] <= array[child_pos])
        return;
    swap(array[child_pos], array[par_pos]);
    heapify_up(par_pos);
}

template <class type>
void Min_Heap<type>::heapify_down(int parent_pos) // O(logn)
{
    int child_pos(left(parent_pos));
    int right_child(right(parent_pos));

    if (child_pos == -1)
        return;

    if (right_child != -1 && array[right_child] <= array[child_pos])
        child_pos = right_child;

    if (array[parent_pos] > array[child_pos])
    {
        swap(array[parent_pos], array[child_pos]);
        heapify_down(child_pos);
    }
}

template <class type>
void Min_Heap<type>::heapify() // O(n)
{
    for (int i((size >> 1) - 1); i >= 0; --i)
        heapify_down(i);
}

template <class type>
void Min_Heap<type>::push(type val)
{
    assert(size + 1 <= capacity);
    array[size++] = val;
    heapify_up(size - 1);
}

template <class type>
void Min_Heap<type>::pop()
{
    assert(!is_empty());
    array[0] = array[--size];
    heapify_down(0);
}

template <class type>
type Min_Heap<type>::top()
{
    assert(!is_empty());
    return array[0];
}

template <class type>
bool Min_Heap<type>::is_empty()
{
    return size == 0;
}