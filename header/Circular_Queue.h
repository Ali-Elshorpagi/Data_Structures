#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Circular_Queue
{
    ll front{};
    ll rear{};
    ll size{};
    ll added_elements{};
    type *arr{};

public:
    Circular_Queue(ll sz);
    ~Circular_Queue();
    bool is_full();
	bool is_empty();
    ll get_size();
	ll next(ll pos);
    void enqueue(type val);
};
