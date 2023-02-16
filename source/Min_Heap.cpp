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
    assert((ll)vec.size() <= capacity);
    array = new type[capacity]{};
    size = vec.size();
    for (ll i(0); i < (ll)vec.size(); ++i)
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
ll Min_Heap<type>::left(ll pos)
{
    ll p((pos << 1) + 1);
    return p >= size ? -1 : p;
}

template <class type>
ll Min_Heap<type>::right(ll pos)
{
    ll p((pos << 1) + 2);
    return p >= size ? -1 : p;
}

template <class type>
ll Min_Heap<type>::parent(ll pos)
{
    return pos == 0 ? -1 : ((pos - 1) >> 1);
}

template <class type>
void Min_Heap<type>::heapify_up(ll child_pos)
{
    ll par_pos(parent(child_pos));
    if (!child_pos || array[par_pos] <= array[child_pos])
        return;
    swap(array[child_pos], array[par_pos]);
    heapify_up(par_pos);
}

template <class type>
void Min_Heap<type>::heapify_down(ll parent_pos) // O(logn)
{
    ll child_pos(left(parent_pos));
    ll right_child(right(parent_pos));

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
    for (ll i((size >> 1) - 1); i >= 0; --i)
        heapify_down(i);
}

template <class type>
bool Min_Heap<type>::is_heap(ll parent_pos) // O(n)
{
    if (parent_pos == -1)
        return true;

    ll left_child(left(parent_pos)), right_child(right(parent_pos));

    if (left_child != -1 && array[parent_pos] > array[left_child])
        return false;

    if (right_child != -1 && array[parent_pos] > array[right_child])
        return false;

    return is_heap(left_child) && is_heap(right_child);
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
ll Min_Heap<type>::get_size()
{
    return size;
}

template <class type>
bool Min_Heap<type>::is_empty()
{
    return size == 0;
}

template <class type>
void Min_Heap<type>::print_less_than(type val, ll pos)
{
    if (array[pos] >= val || pos == -1)
        return;
    cout << array[pos] << ' ';
    print_less_than(val, left(pos));
    print_less_than(val, right(pos));
}

template <class type>
bool Min_Heap<type>::is_heap_array(type *p, ll n)
{
    type *old_arr = array;
    ll old_size = size;
    array = p;
    size = n;
    bool result(is_heap(0));
    size = old_size;
    array = old_arr;
    return result;
}

template <class type>
void Min_Heap<type>::heap_sort_0(type *p, ll n)
{
    if (n <= 1)
        return;
    type *old_arr = array;
    ll old_size = size;

    for (ll i(0); i < n; ++i)
        push(p[i]);

    ll j(0);
    while (!is_empty())
        p[j++] = top(), pop();

    size = old_size;
    array = old_arr;
}

template <class type>
void Min_Heap<type>::heap_sort_1(type *p, ll n) // O(nlogn)
{
    if (n <= 1)
        return;
    type *old_arr = array;
    ll old_size = size;
    size = n;
    array = p;

    heapify();     // O(n)
    while (size--) // O(nlogn)
    {
        swap(array[0], array[size]);
        heapify_down(0);
    }

    for (ll i(0); i < (n >> 1); ++i)
        swap(array[i], array[n - i - 1]);

    size = old_size;
    array = old_arr;
}