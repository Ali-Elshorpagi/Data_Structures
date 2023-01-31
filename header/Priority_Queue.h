#pragma once

#include "Circular_Queue.h"
#include "../source/Circular_Queue.cpp"

template <class type>
class Priority_Queue
{
    ll size{};
    ll added_elements{};
    Circular_Queue<type> q1, q2, q3;

public:
    Priority_Queue(ll sz);
    ~Priority_Queue();
    bool is_empty();
	bool is_full();
};
