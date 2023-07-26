#ifndef MAX_HEAP_CPP
#define MAX_HEAP_CPP

#include "../header/Max_Heap.h"

template <class type>
Max_Heap<type>::Max_Heap()
{
    array = new type[capacity]{};
}

template <class type>
Max_Heap<type>::Max_Heap(const std::vector<type> &vec)
{
    if ((int)vec.size() >= capacity)
        expand_capacity();
    array = new type[capacity]{};
    size = (int)vec.size();
    for (int i(0); i < (int)vec.size(); ++i)
        array[i] = vec[i];
    heapify();
}

template <class type>
void Max_Heap<type>::expand_capacity()
{
    capacity <<= 1;
    type *tmp(new type[capacity]{});
    for (int i(0); i < size; ++i)
        tmp[i] = array[i];
    std::swap(array, tmp);
    delete[] tmp;
}

template <class type>
Max_Heap<type>::~Max_Heap()
{
    delete[] array;
    array = nullptr;
}

template <class type>
int Max_Heap<type>::left(int pos)
{
    int p((pos << 1) + 1);
    return p >= size ? -1 : p;
}

template <class type>
int Max_Heap<type>::right(int pos)
{
    int p((pos << 1) + 2);
    return p >= size ? -1 : p;
}

template <class type>
int Max_Heap<type>::parent(int pos)
{
    return (!pos ? -1 : ((pos - 1) >> 1));
}

template <class type>
void Max_Heap<type>::heapify_up(int child_pos)
{
    int par_pos(parent(child_pos));
    if (!child_pos || array[par_pos] > array[child_pos])
        return;
    std::swap(array[child_pos], array[par_pos]);
    heapify_up(par_pos);
}

template <class type>
void Max_Heap<type>::heapify_down(int parent_pos) // O(logn)
{
    int child_pos(left(parent_pos)), right_child(right(parent_pos));

    if (child_pos == -1)
        return;

    if (right_child != -1 && array[right_child] > array[child_pos])
        child_pos = right_child;

    if (array[parent_pos] < array[child_pos])
    {
        std::swap(array[parent_pos], array[child_pos]);
        heapify_down(child_pos);
    }
}

template <class type>
void Max_Heap<type>::heapify() // O(n)
{
    for (int i((size >> 1) - 1); i > -1; --i)
        heapify_down(i);
}

template <class type>
void Max_Heap<type>::push(type val)
{
    if (size == capacity)
        expand_capacity();
    array[size++] = val;
    heapify_up(size - 1);
}

template <class type>
void Max_Heap<type>::pop()
{
    assert(!is_empty());
    array[0] = array[--size];
    heapify_down(0);
}

template <class type>
type Max_Heap<type>::top()
{
    assert(!is_empty());
    return array[0];
}

template <class type>
const int Max_Heap<type>::get_size()
{
    return size;
}

template <class type>
bool Max_Heap<type>::is_empty()
{
    return size == 0;
}

template <class type>
bool Max_Heap<type>::search(type val)
{
    for (int i(0); i < size; ++i)
    {
        if (array[i] == val)
            return true;
    }
    return false;
}
#endif