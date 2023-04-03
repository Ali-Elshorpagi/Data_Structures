#include "../header/Min_Heap.h"

template <class type>
Min_Heap<type>::Min_Heap()
{
    array = new type[capacity]{};
}

template <class type>
Min_Heap<type>::Min_Heap(const vector<type> &vec) // Floyd Algorithm
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
Min_Heap<type>::~Min_Heap()
{
    delete[] array;
    array = nullptr;
}

template <class type>
void Min_Heap<type>::expand_capacity()
{
    capacity <<= 1;
    type *tmp(new type[capacity]{});
    for (int i(0); i < size; ++i)
        tmp[i] = array[i];
    swap(array, tmp);
    delete[] tmp;
}

template <class type>
int Min_Heap<type>::left(int pos)
{
    // pos = parent's pos
    // p_left = (2 * pos) + 1;
    int p_left((pos << 1) + 1);
    return p_left >= size ? -1 : p_left;
}

template <class type>
int Min_Heap<type>::right(int pos)
{
    // pos = parent's pos
    // p_right = (2 * pos) + 2;
    int p_right((pos << 1) + 2);
    return p_right >= size ? -1 : p_right;
}

template <class type>
int Min_Heap<type>::parent(int pos)
{
    // pos = child's pos
    // p_parent = floor((pos - 1) / 2);
    // we don't need floor cus the integer;
    return (!pos ? -1 : ((pos - 1) >> 1));
}

template <class type>
void Min_Heap<type>::heapify_up(int child_pos)
{
    int par_pos(parent(child_pos));
    if (!child_pos || array[par_pos] < array[child_pos])
        return;
    swap(array[child_pos], array[par_pos]);
    heapify_up(par_pos);
}

template <class type>
void Min_Heap<type>::heapify_down(int parent_pos) // O(logn)
{
    int child_pos(left(parent_pos)), right_child(right(parent_pos));

    if (child_pos == -1) // no children
        return;

    if (right_child != -1 && array[right_child] < array[child_pos]) // is right smaller than left?
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
    // if we have N nodes, so clearly we have floor(N / 2) non-leaf nodes;
    // so the formula wil be (N / 2 - 1) cus it 's 0-based and integer so we don' t need floor;
    for (int i((size >> 1) - 1); i > -1; --i)
        heapify_down(i);
}

template <class type>
bool Min_Heap<type>::is_heap(int parent_pos) // O(n)
{
    if (parent_pos == -1)
        return true;

    int left_child(left(parent_pos)), right_child(right(parent_pos));

    if (left_child != -1 && array[parent_pos] > array[left_child])
        return false;

    if (right_child != -1 && array[parent_pos] > array[right_child])
        return false;

    return is_heap(left_child) && is_heap(right_child);
}

template <class type>
void Min_Heap<type>::push(type val)
{
    if (size == capacity)
        expand_capacity();
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
int Min_Heap<type>::get_size()
{
    return size;
}

template <class type>
bool Min_Heap<type>::is_empty()
{
    return size == 0;
}

template <class type>
void Min_Heap<type>::print_less_than(type val, int pos)
{
    if (array[pos] >= val || pos == -1)
        return;
    cout << array[pos] << ' ';
    print_less_than(val, left(pos));
    print_less_than(val, right(pos));
}

template <class type>
bool Min_Heap<type>::is_heap_array(type *p, int n)
{
    type *old_arr(array);
    int old_size(size);
    array = p, size = n;
    bool result(is_heap(0));
    size = old_size, array = old_arr;
    return result;
}

template <class type>
void Min_Heap<type>::heap_sort(type *p, int n) // O(nlogn)
{
    if (n < 2)
        return;

    type *old_arr(array);
    int old_size(size);
    size = n, array = p;

    heapify();     // O(n)
    while (size--) // O(nlogn)
    {
        swap(array[0], array[size]);
        heapify_down(0);
    }

    for (int i(0); i < (n >> 1); ++i) // reverse the array
        swap(array[i], array[n - i - 1]);

    size = old_size, array = old_arr;
}