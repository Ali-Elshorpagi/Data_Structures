#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Min_Heap
{
    type *array{};
    ll size{}, capacity{1000};
    ll left(ll pos);
    ll right(ll pos);
    ll parent(ll pos);
    void heapify_up(ll child_pos);
    void heapify_down(ll parent_pos);
    void heapify();
    bool is_heap(ll parent_pos);

public:
    Min_Heap();
    Min_Heap(const vector<type> &v);
    ~Min_Heap();
    void push(type val);
    void pop();
    type top();
    ll get_size();
    bool is_empty();
    void print_less_than(type val, ll pos = 0);
    bool is_heap_array(type *p, ll n);
    void heap_sort_0(type *p, ll n);
    void heap_sort_1(type *p, ll n);
};
