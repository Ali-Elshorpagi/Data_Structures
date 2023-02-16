#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Priority_Queue
{
    ll capacity{1000};
    type *key{};
    type *value{};
    ll size{};

    ll left(ll pos);
    ll right(ll pos);
    ll parent(ll pos);
    void heapify_up(ll child_pos);
    void heapify_down(ll parent_pos);

public:
    Priority_Queue();
    ~Priority_Queue();
    bool is_empty();
    void enqueue(type val, ll priority);
    type dequeue();
    type top();
};
