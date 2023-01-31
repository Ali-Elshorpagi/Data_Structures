#pragma once
#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Deque
{
    ll size{};
    ll front{0};
    ll rear{0};
    ll added_elements{};
    type *array{};

public:
    Deque(int size);
    ~Deque();
    ll next(ll pos);
    ll prev(ll pos);
    void enqueue_rear(type val);
    void enqueue_front(type val);
    type dequeue_front();
    type dequeue_rear();
    int is_empty();
    bool is_full();
    void print();
};
