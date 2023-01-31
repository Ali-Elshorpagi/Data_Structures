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
};
