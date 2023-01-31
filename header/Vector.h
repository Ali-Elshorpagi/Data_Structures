#pragma once
#include <cassert>
#include <iostream>

using namespace std;

typedef long long ll;

template <class type>
class Vector
{
    type *arr{nullptr};
    ll size{0};
    ll capacity{};

public:
    Vector(ll sz);
    ~Vector();
    void expand_capacity();
    ll get_size();
    type get_value(ll idx);
    type get_front();
    type get_back();
    void set_value(ll idx, type val);
    void print();
     ll find(type val);
    void push_back(type val);
     void insert(ll idx, type val);
      void right_rotate();
      void left_rotate();
    void right_rotate(ll times);
    template <class type>
void Vector<type>::left_rotate()
{
    type first_element = arr[0];
    for (int p(1); p < size; ++p)
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


};
