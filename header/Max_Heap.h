#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Max_Heap
{
    type *array{};
    ll size{}, capacity{1000}; // we can make expand the capacity
    ll left(ll pos);
    ll right(ll pos);
    ll parent(ll pos);
    void heapify_up(ll child_pos);
    void heapify_down(ll parent_pos);
    void heapify();

public:
    Max_Heap();
    Max_Heap(const vector<type> &vec);
    ~Max_Heap();
    void push(type val);
    void pop();
    type top();
    ll get_size();
    bool is_empty();
};
