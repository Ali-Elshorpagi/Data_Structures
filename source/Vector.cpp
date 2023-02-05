#include "..\\header\Vector.h"

template <class type>
Vector<type>::Vector(ll sz) : size(sz)
{
    if (size < 0)
        size = 1;
    capacity = size + 10;
    arr = new type[capacity]{};
}

template <class type>
Vector<type>::~Vector()
{
    delete[] arr;
    arr = nullptr;
}

template <class type>
void Vector<type>::expand_capacity()
{
    capacity *= 2;
    type *arr2 = new type[capacity]{};
    for (ll i(0); i < size; ++i)
        arr2[i] = arr[i];
    swap(arr, arr2);
    delete[] arr2;
}

template <class type>
ll Vector<type>::get_size()
{
    return size;
}

template <class type>
type Vector<type>::get_value(ll idx)
{
    assert(idx >= 0 && idx < size);
    return arr[idx];
}

template <class type>
type Vector<type>::get_front()
{
    return arr[0];
}

template <class type>
type Vector<type>::get_back()
{
    return arr[size - 1];
}

template <class type>
void Vector<type>::set_value(ll idx, type val)
{
    assert(idx >= 0 && idx < size);
    arr[idx] = val;
}

template <class type>
void Vector<type>::print()
{
    for (ll i(0); i < size; ++i)
        cout << arr[i] << ' ';
    cout << edl;
}

template <class type>
ll Vector<type>::find(type val)
{
    for (ll i(0); i < size; ++i)
        if (arr[i] == val)
            return i;
    return -1;
}

template <class type>
void Vector<type>::push_back(type val)
{
    if (size == capacity)
        expand_capacity();
    arr[size++] = val;
}

template <class type>
void Vector<type>::insert(ll idx, type val)
{
    assert(0 <= idx && idx < size);
    if (size == capacity)
        expand_capacity();
    for (ll p(size - 1); p >= idx; --p)
        arr[p + 1] = arr[p];
    arr[idx] = val;
    ++size;
}

template <class type>
void Vector<type>::right_rotate()
{
    type last_element(arr[size - 1]);
    for (ll p(size - 2); p >= 0; --p)
        arr[p + 1] = arr[p];
    arr[0] = last_element;
}

template <class type>
void Vector<type>::left_rotate()
{
    type first_element(arr[0]);
    for (ll p(1); p < size; ++p)
        arr[p - 1] = arr[p];
    arr[size - 1] = first_element;
}

template <class type>
void Vector<type>::right_rotate(ll times)
{
    times %= size;
    while (times--)
        right_rotate();
}

template <class type>
type Vector<type>::pop(ll idx)
{
    assert(idx >= 0 && idx < size);
    type val(arr[idx]);
    for (ll p(idx + 1); p < size; ++p)
        arr[p - 1] = arr[p];
    --size;
    return val;
}

template <class type>
ll Vector<type>::find_transposition(type val)
{
    for (ll i(0); i < size; ++i)
        if (arr[i] == val)
        {
            if (i == 0)
                return 0;
            swap(arr[i], arr[i - 1]);
            return i - 1;
        }
    return -1;
}
