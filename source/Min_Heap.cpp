#ifndef MIN_HEAP_CPP
#define MIN_HEAP_CPP

#include "../header/Min_Heap.h"

template <class type>
Min_Heap<type>::Min_Heap()
{
    array = new type[capacity]{};
}

template <class type>
Min_Heap<type>::Min_Heap(const std::vector<type> &vec) // Floyd Algorithm
{
    while ((int)vec.size() >= capacity)
        capacity <<= 1;
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
    std::swap(array, tmp);
    delete[] tmp;
}

template <class type>
int Min_Heap<type>::left(int pos) const
{
    // pos = parent's pos
    // p_left = (2 * pos) + 1;
    int p_left((pos << 1) + 1);
    return p_left >= size ? -1 : p_left;
}

template <class type>
int Min_Heap<type>::right(int pos) const
{
    // pos = parent's pos
    // p_right = (2 * pos) + 2;
    int p_right((pos << 1) + 2);
    return p_right >= size ? -1 : p_right;
}

template <class type>
int Min_Heap<type>::parent(int pos) const
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
    std::swap(array[child_pos], array[par_pos]);
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
        std::swap(array[parent_pos], array[child_pos]);
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
type Min_Heap<type>::top() const
{
    assert(!is_empty());
    return array[0];
}

template <class type>
int Min_Heap<type>::get_size() const
{
    return size;
}

template <class type>
bool Min_Heap<type>::is_empty() const
{
    return size == 0;
}

template <class type>
void Min_Heap<type>::print_less_than(type val, int pos) const
{
    if (pos == -1 || array[pos] >= val)
        return;
    std::cout << array[pos] << ' ';
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
void Min_Heap<type>::heap_sort(type *p, int n) // O(N* log(N)) time
{
    if (n < 2)
        return;

    type *old_arr(array);
    int old_size(size);
    size = n, array = p;

    heapify();     // O(n)
    while (size--) // O(nlogn)
    {
        std::swap(array[0], array[size]);
        heapify_down(0);
    }

    for (int i(0); i < (n >> 1); ++i) // reverse the array
        std::swap(array[i], array[n - i - 1]);

    size = old_size, array = old_arr;
}

template <class type>
bool Min_Heap<type>::search_helper(type val, int pos) const
{
    if (pos == -1 || pos >= size)
        return false;

    if (array[pos] == val)
        return true;

    // For Min_Heap: if current > val, children will be even larger
    if (array[pos] > val)
        return false;

    // Search left and right subtrees
    return search_helper(val, left(pos)) || search_helper(val, right(pos));
}

template <class type>
bool Min_Heap<type>::search(type val) const
{
    return search_helper(val, 0);
}
#endif