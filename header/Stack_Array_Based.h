#pragma once

#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;
#define edl '\n'

template <class type>
class Stack_Array_Based
{
    unsigned long long size{};
    type *arr{};
    ll top{};

public:
    Stack_Array_Based(unsigned long long size);
    ~Stack_Array_Based();
    bool is_full();
	bool is_empty();
    void push(type val);

    type peek();
};
