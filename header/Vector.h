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


};
