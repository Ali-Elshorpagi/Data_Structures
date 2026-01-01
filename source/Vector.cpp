#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../header/Vector.h"

template <class type>
Vector<type>::Vector(int sz) : size(sz)
{
  if (size < 0)
    size = 1;
  capacity = size + 10;
  arr = new type[capacity]{};
}

template <class type>
Vector<type>::Vector(const Vector<type> &other)
{
  size = other.size;
  capacity = other.capacity;
  arr = new type[capacity];
  for (int i(0); i < size; ++i)
    arr[i] = other.arr[i];
}

template <class type>
Vector<type> &Vector<type>::operator=(const Vector<type> &other)
{
  if (this != &other)
  {
    delete[] arr;
    size = other.size;
    capacity = other.capacity;
    arr = new type[capacity];
    for (int i(0); i < size; ++i)
      arr[i] = other.arr[i];
  }
  return *this;
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
  capacity <<= 1;
  type *tmp(new type[capacity]{});
  for (int i(0); i < size; ++i)
    tmp[i] = arr[i];
  std::swap(arr, tmp);
  delete[] tmp;
}

template <class type>
type &Vector<type>::operator[](const int idx)
{
  assert(idx > -1 && idx < size);
  return arr[idx];
}

template <class type>
const int Vector<type>::get_size() { return size; }

template <class type>
const type Vector<type>::get_value(int idx)
{
  assert(idx > -1 && idx < size);
  return arr[idx];
}

template <class type>
const type Vector<type>::get_front() { return arr[0]; }

template <class type>
const type Vector<type>::get_back()
{
  return arr[size - 1];
}

template <class type>
const bool Vector<type>::is_empty() { return size == 0; }

template <class type>
void Vector<type>::set_value(int idx, type val)
{
  assert(idx > -1 && idx < size);
  arr[idx] = val;
}

template <class type>
const void Vector<type>::print()
{
  for (int i(0); i < size; ++i)
    std::cout << arr[i] << ' ';
  std::cout << edl;
}

template <class type>
const int Vector<type>::find(type val)
{
  for (int i(0); i < size; ++i)
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
void Vector<type>::pop_back()
{
  assert(size > 0);
  --size;
  arr[size].~type();
}

template <class type>
type Vector<type>::pop(int idx)
{
  assert(idx > -1 && idx < size);
  type val(arr[idx]);
  for (int i(idx + 1); i < size; ++i)
    arr[i - 1] = arr[i];
  --size;
  return val;
}

template <class type>
void Vector<type>::remove(type val)
{
  for (int i(0); i < size; ++i)
  {
    if (arr[i] == val)
      pop(i), --i; // since items will shift, recheck this index
  }
}

template <class type>
void Vector<type>::insert(int idx, type val)
{
  assert(idx > -1 && idx < size);
  if (size == capacity)
    expand_capacity();
  for (int i(size - 1); i >= idx; --i)
    arr[i + 1] = arr[i];
  arr[idx] = val;
  ++size;
}

template <class type>
void Vector<type>::right_rotate()
{
  type last_element(arr[size - 1]);
  for (int i(size - 2); i > -1; --i)
    arr[i + 1] = arr[i];
  arr[0] = last_element;
}

template <class type>
void Vector<type>::left_rotate()
{
  type first_element(arr[0]);
  for (int i(1); i < size; ++i)
    arr[i - 1] = arr[i];
  arr[size - 1] = first_element;
}

template <class type>
void Vector<type>::right_rotate(int times)
{
  times %= size;
  while (times--)
    right_rotate();
}

template <class type>
int Vector<type>::find_transposition(type val)
{
  for (int i(0); i < size; ++i)
    if (arr[i] == val)
    {
      if (!i)
        return 0;
      std::swap(arr[i], arr[i - 1]);
      return i - 1;
    }
  return -1;
}
#endif