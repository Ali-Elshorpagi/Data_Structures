#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class type>
class Vector
{
    type *arr{nullptr};
    int size{};
    int capacity{};

    void expand_capacity();

public:
    Vector(int sz);
    ~Vector();
    type &operator[](const int idx);
    int get_size();
    type get_value(int idx);
    type get_front();
    type get_back();
    void set_value(int idx, type val);
    void print();
    int find(type val);
    void push_back(type val);
    void insert(int idx, type val);
    void right_rotate();
    void left_rotate();
    void right_rotate(int times);
    type pop(int idx);
    int find_transposition(type val);
};