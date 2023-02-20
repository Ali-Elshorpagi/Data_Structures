#include "..\\header\Priority_Queue_Heap_Based.h"

template <class type>
Priority_Queue_Heap_Based<type>::Priority_Queue_Heap_Based()
{
    key = new type[capacity]{};
    value = new type[capacity]{};
    size = 0;
}

template <class type>
Priority_Queue_Heap_Based<type>::~Priority_Queue_Heap_Based()
{
    delete[] key;
    delete[] value;
}

template <class type>
int Priority_Queue_Heap_Based<type>::left(int pos)
{
    int p((pos << 1) + 1);
    return p >= size ? -1 : p;
}

template <class type>
int Priority_Queue_Heap_Based<type>::right(int pos)
{
    int p((pos << 1) + 2);
    return p >= size ? -1 : p;
}

template <class type>
int Priority_Queue_Heap_Based<type>::parent(int pos)
{
    return pos == 0 ? -1 : ((pos - 1) >> 1);
}

template <class type>
void Priority_Queue_Heap_Based<type>::heapify_up(int child_pos)
{
    int par_pos(parent(child_pos));
    if (!child_pos || key[par_pos] > key[child_pos])
        return;
    swap(key[child_pos], key[par_pos]);
    swap(value[child_pos], value[par_pos]);
    heapify_up(par_pos);
}

template <class type>
void Priority_Queue_Heap_Based<type>::heapify_down(int parent_pos) // O(logn)
{
    int child_pos(left(parent_pos)), right_child(right(parent_pos));

    if (child_pos == -1)
        return;

    if (right_child != -1 && key[right_child] > key[child_pos])
        child_pos = right_child;

    if (key[parent_pos] < key[child_pos])
    {
        swap(key[parent_pos], key[child_pos]);
        swap(value[parent_pos], value[child_pos]);
        heapify_down(child_pos);
    }
}

template <class type>
bool Priority_Queue_Heap_Based<type>::is_empty()
{
    return size == 0;
}

template <class type>
void Priority_Queue_Heap_Based<type>::enqueue(type val, int priority)
{
    assert(size + 1 <= capacity);
    value[size] = val;
    key[size++] = priority;
    heapify_up(size - 1);
}

template <class type>
type Priority_Queue_Heap_Based<type>::dequeue()
{
    assert(!is_empty());
    type ret(value[0]);
    key[0] = key[--size];
    value[0] = value[size];
    heapify_down(0);
    return ret;
}

template <class type>
type Priority_Queue_Heap_Based<type>::top()
{
    assert(!is_empty());
    return value[0];
}